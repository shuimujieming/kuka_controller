#ifndef MYTHREADTCP_H
#define MYTHREADTCP_H
#include "QThread"

#include <iostream>  
#include <sstream>
#include "MyTCP.h"


class MyThreadTCP :public QThread
{
	Q_OBJECT

public:
	MyThreadTCP();
	~MyThreadTCP();

    void getFpsPtr(int* ptr);

	void run();
    void getTCPPtr(MyTCP* tcp);
    void getPositionPtr(double* x, double*y, double*z, double*a, double*b, double*c);
    //传感器数据采集FIFO变量
    int index = 0;
    uint8_t pbuf[32];
    //机器人位姿数据
    double *X, *Y, *Z, *A, *B, *C;
    int* fps;

signals:
	void mess();
    void sendSerialData(double* Fx, double*Fy, double*Fz, double*Mx, double*My, double*Mz);

private:
    MyTCP* tcpPtr = NULL;


public slots:
    void OnServerReadData();

};

#endif // MYTHREAD_H
#pragma once
