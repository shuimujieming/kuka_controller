#include "../include/kuka_controller/MyThreadTCP.h"

using namespace std;

MyThreadTCP::MyThreadTCP()
{

}

MyThreadTCP::~MyThreadTCP()
{
    terminate();
    if (tcpPtr != NULL)
    {
        delete tcpPtr;
    }
}

void MyThreadTCP::getTCPPtr(MyTCP* tcp)
{
    tcpPtr = tcp;
}

void MyThreadTCP::getPositionPtr(double* x, double*y, double*z, double*a, double*b, double*c)
{
    X = x;
    Y = y;
    Z = z;
    A = a;
    B = b;
    C = c;
}

void MyThreadTCP::run()
{
    if (tcpPtr == NULL){
        return;
    }
    connect(tcpPtr->MyTCPSocket, SIGNAL(readyRead()), this, SLOT(OnServerReadData()));
    exec();
}

void MyThreadTCP::getFpsPtr(int* ptr)
{
    fps = ptr;
}

void MyThreadTCP::OnServerReadData()
{
    string xyzabc;

    char buffer[1024] = { 0 };

    tcpPtr->MyTCPSocket->read(buffer, 1024);

    if (strlen(buffer) > 20)
    {
        //接收的位姿数据
        xyzabc = buffer;
        //xyzabc数据
        string x = xyzabc.substr(xyzabc.find("X=\"") + 3, xyzabc.find("\" Y=") - xyzabc.find("X=\"") - 3);
        string y = xyzabc.substr(xyzabc.find("Y=\"") + 3, xyzabc.find("\" Z=") - xyzabc.find("Y=\"") - 3);
        string z = xyzabc.substr(xyzabc.find("Z=\"") + 3, xyzabc.find("\" A=") - xyzabc.find("Z=\"") - 3);
        string a = xyzabc.substr(xyzabc.find("A=\"") + 3, xyzabc.find("\" B=") - xyzabc.find("A=\"") - 3);
        string b = xyzabc.substr(xyzabc.find("B=\"") + 3, xyzabc.find("\" C=") - xyzabc.find("B=\"") - 3);
        string c = xyzabc.substr(xyzabc.find("C=\"") + 3, xyzabc.find("\"></LastPos>") - xyzabc.find("C=\"") - 3);
        //axis六轴数据
        string a1 = xyzabc.substr(xyzabc.find("<Axis1>") + 7, xyzabc.find("</Axis1>") - xyzabc.find("<Axis1>") - 7);
        string a2 = xyzabc.substr(xyzabc.find("<Axis2>") + 7, xyzabc.find("</Axis2>") - xyzabc.find("<Axis2>") - 7);
        string a3 = xyzabc.substr(xyzabc.find("<Axis3>") + 7, xyzabc.find("</Axis3>") - xyzabc.find("<Axis3>") - 7);
        string a4 = xyzabc.substr(xyzabc.find("<Axis4>") + 7, xyzabc.find("</Axis4>") - xyzabc.find("<Axis4>") - 7);
        string a5 = xyzabc.substr(xyzabc.find("<Axis5>") + 7, xyzabc.find("</Axis5>") - xyzabc.find("<Axis5>") - 7);
        string a6 = xyzabc.substr(xyzabc.find("<Axis6>") + 7, xyzabc.find("</Axis6>") - xyzabc.find("<Axis6>") - 7);


        //字符串和数字转换
        double xx, yy, zz, aa, bb, cc;
        istringstream(x) >> xx;
        istringstream(y) >> yy;
        istringstream(z) >> zz;
        istringstream(a) >> aa;
        istringstream(b) >> bb;
        istringstream(c) >> cc;

        *X = xx;
        *Y = yy;
        *Z = zz;
        *A = aa;
        *B = bb;
        *C = cc;
    }

}
