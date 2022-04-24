#include "../include/kuka_controller/MyThreadForce.h"


MyThreadForce::MyThreadForce()
{

}

MyThreadForce::~MyThreadForce()
{
    terminate();
    if (forcePtr != NULL)
    {
        delete forcePtr;
    }
}

void MyThreadForce::getForcePtr(MyTCPForce* force)
{
    forcePtr = force;
}

void MyThreadForce::getForcePtr(double* x, double*y, double*z, double*mx, double*my, double*mz)
{
    Fx = x;
    Fy = y;
    Fz = z;
    Mx = mx;
    My = my;
    Mz = mz;
}

void MyThreadForce::run()
{
    if (forcePtr == NULL){
        return;
    }

    connect(forcePtr->MyTCPSocket,SIGNAL(readyRead()),this,SLOT(OnForceReadData()));
    exec();
}


void MyThreadForce::getFpsPtr(int* ptr)
{
    fps = ptr;
}

void MyThreadForce::OnForceReadData()
{
    static int err_count = 0;

    //从接收缓冲区中读取数据
    QByteArray buffer;
    //每次读取基本都>=32字节且是32的整数倍，或者为2，即是帧头或帧尾
    buffer = QByteArray(forcePtr->MyTCPSocket->readAll());
    //转成16进制数据
    //若要查看需先转换成char字符
    uint8_t* pdata = (uint8_t*)buffer.data();

    //遍历接收数据，获取数据内部的帧数据
    for (int i = 0; i < buffer.size(); i++)
    {
        //pbuf当前等待第一个字节数据，即最后一个数据已经获取完成或刚开始获取数据
        if (index == 0)
        {
            //检查头两个字节是否为校验码
            while (!((pdata[i] == 0xf6) && (pdata[i + 1] == 0x6f)))
            {
                //最后两字节限制，防止越界
                if (i < buffer.size() - 2)
                {
                    i++;
                }
                else
                {
                    //数据读取完且未发现帧头，直接结束读取
                    return;
                }
            }
            //读入帧头
            pbuf[0] = pdata[i];
            pbuf[1] = pdata[i + 1];
            i += 1;
            index += 2;
        }
        else
        {
            //读入帧数据
            pbuf[index] = pdata[i];
            index++;
            //读取完整帧数据
            if (index == 32)
            {
                //校验通过
                if (forcePtr->crc_cal_by_byte(&pbuf[3], 27) == (pbuf[31] << 8 | pbuf[30]))
                {
                    //六维力数据获取
                    *Fx = forcePtr->bit8Tobit32(&pbuf[6]) / 1000.0f;
                    *Fy = forcePtr->bit8Tobit32(&pbuf[10]) / 1000.0f;
                    *Fz = forcePtr->bit8Tobit32(&pbuf[14]) / 1000.0f;
                    *Mx = forcePtr->bit8Tobit32(&pbuf[18]) / 1000.0f;
                    *My = forcePtr->bit8Tobit32(&pbuf[22]) / 1000.0f;
                    *Mz = forcePtr->bit8Tobit32(&pbuf[26]) / 1000.0f;


                    (*fps) ++ ;
                }
                else
                {   //校验未通过
                    err_count++;
                    std::cout << "校验失败" << err_count << "次！" << std::endl;
                }
            }
            //读取新的一帧
            index %= 32;
        }
    }
}
