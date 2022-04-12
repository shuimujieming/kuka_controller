#pragma once

#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include <iostream>
#include <sstream>
using namespace std;

class MyTCP
{
public:
	MyTCP();

	int OpenTCP(int port);
	int CloseTCP();
    int SendData(string data);
    int CtrlRobot(float x,float y,float z,float a,float b,float c);

	QTcpServer* MyTCPServer;
	QTcpSocket* MyTCPSocket;
private:

};

