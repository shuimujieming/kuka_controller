#include "../include/kuka_controller/MyTCPForce.h"

MyTCPForce::MyTCPForce()
{
    MyTCPSocket = new QTcpSocket();
}
int MyTCPForce::OpenTCP(QString ip, quint16 port)
{
    //异步操作，连接成功后会发送connected信号
    MyTCPSocket->connectToHost(ip,port);

    if(MyTCPSocket->waitForConnected(1000))
    {
        qDebug("ok");
        return 0;
    }
    else {
        qDebug("fail");
        return -1;
    }
}

int MyTCPForce::SendData(string data)
{

    if (MyTCPSocket->isValid())
    {
        int Ret = MyTCPSocket->write(data.c_str(), strlen(data.c_str()));
        if (Ret == -1)
        {
            return -1;
        }
        else
            return 0;
    }
    else
        return -1;
}
int MyTCPForce::CloseTCP()
{


    if (MyTCPSocket != NULL)
    {
        MyTCPSocket->disconnectFromHost();
        MyTCPSocket->close();
    }

    return 0;
}


//8位合成32位数据
int32_t MyTCPForce::bit8Tobit32(uint8_t* change_data)
{
    union
    {
        int32_t f;
        uint8_t byte[4];
    }u32val;
    u32val.byte[0] = change_data[0];
    u32val.byte[1] = change_data[1];
    u32val.byte[2] = change_data[2];
    u32val.byte[3] = change_data[3];
    return u32val.f;
}

//QString转16进制
void MyTCPForce::convertStringToHex(QString& str, QByteArray& byteData)
{
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len / 2);
    char lstr, hstr;
    for (int i = 0; i < len; )
    {
        //char lstr,
        //高位数据
        //0xfe
        //f
        hstr = str[i].toLatin1(); //Latin1代表ASCII，Local8Bit代表unicode
        if (hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if (i >= len)
            break;
        //低位数据
        //0xfe
        //e
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if ((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            //转位0xfe，f左移四位即*16
            hexdata = hexdata * 16 + lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

//char转16进制
char MyTCPForce::convertCharToHex(char ch)
{
    /*
    0x30等于十进制的48，48也是0的ASCII值，，
    */
    //字符0-9转为十六进制0-9
    if ((ch >= '0') && (ch <= '9'))
        return ch - 0x30;
    //字符a-f，转十六进值a-f，即10-15
    else if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;
    else if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;
    else return (-1);
}


//发送字符数据
void MyTCPForce::sendInfo(char* info, int len) {

    for (int i = 0; i < len; ++i)
    {
        printf("0x%x\n", info[i]);
    }
    MyTCPSocket->write(info, len);
}
//发送16进制数据
void MyTCPForce::sendInfo(QString& info) {

    QByteArray sendBuf;
    if (info.contains(" "))
    {
        info.replace(QString(" "), QString(""));//把空格去掉
    }
    convertStringToHex(info, sendBuf); //把QString 转换 为 hex

    MyTCPSocket->write(sendBuf);

}
/* CRC字节表 */

//CRC16校验
//CRC校验范围为有效数据范围（设备地址~内容）
uint16_t MyTCPForce::crc_cal_by_byte(unsigned char* ptr, unsigned char len)
{
    unsigned short crc = 0xffff;
    while (len-- != 0)
    {
        unsigned int high = (unsigned int)(crc / 256);
        crc <<= 8;
        crc ^= crc_ta_8[high ^ *ptr];
        ptr++;
    }
    return crc;
}

void MyTCPForce::startGrab()
{
    //发送数据
    //16进制
    //连续采集
    QString sendBuf = QString("f6 6f 03 00 00 02 de ec 6f f6");;
    //发送串口数据
    sendInfo(sendBuf);
}

void MyTCPForce::stopGrab()
{
    //发送数据
    //16进制
    //发50个0x00阻塞传感器发送
    QString sendBuf = QString("00 00 00 00 00 00 00 00 00 00");
    for (int i = 0; i < 5; i++)
    {
        //发送串口数据
        sendInfo(sendBuf);
    }
    //延时200ms后发送停止采集命令
    //实测效果不好，去掉延时
    //sleep(100);
    sendBuf = QString("f6 6f 03 00 00 03 ff fc 6f f6");
    sendInfo(sendBuf);
}
