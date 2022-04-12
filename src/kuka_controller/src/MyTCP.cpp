#include "../include/kuka_controller/MyTCP.h"


MyTCP::MyTCP()
{
    MyTCPServer = new QTcpServer();
    MyTCPSocket = new QTcpSocket();
}
int MyTCP::SendData(string data)
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
int MyTCP::CtrlRobot(float x,float y,float z,float a,float b,float c)
{
    ostringstream xx;
    ostringstream yy;
    ostringstream zz;
    ostringstream aa;
    ostringstream bb;
    ostringstream cc;

    xx<<x;
    yy<<y;
    zz<<z;
    aa<<a;
    bb<<b;
    cc<<c;


    string data;

    data = "<Sensor><Read><xyzabc X=\"" + xx.str() + "\" Y=\"" + yy.str() + "\" Z=\"" + zz.str() + "\" A=\"" + aa.str() + "\" B=\"" + bb.str() + "\" C=\"" + cc.str() + "\"></xyzabc></Read><WaitRecv>998</WaitRecv></Sensor>";

    if(SendData(data)==-1)
    {
        return -1;
    }
    else
    {
        {
            cout << "发送机械臂目标位置：" << "X = \"" + xx.str() + "\" Y=\"" + yy.str() + "\" Z=\"" + zz.str() + "\" A=\"" + aa.str() + "\" B=\"" + bb.str() + "\" C=\"" + cc.str() << endl;
        }

        return 0;
    }
}

//打开TCP，监听
int MyTCP::OpenTCP(int port)
{
    if (!MyTCPServer->listen(QHostAddress::Any, port))
    {
        return -1;
    }
    return 0;
}
//关闭TCP，断开TCP连接
int MyTCP::CloseTCP()
{
    if (MyTCPServer != NULL)
    {
        MyTCPServer->disconnect();
        MyTCPServer->close();
    }
    if (MyTCPSocket != NULL)
    {
        MyTCPSocket->disconnectFromHost();
        MyTCPSocket->close();
    }

    return 0;
}
