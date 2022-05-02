#ifndef MYTHREADFORCE_H
#define MYTHREADFORCE_H
#include "QThread"

#include <iostream>  
#include <sstream>
#include "MyTCPForce.h"


class MyThreadForce :public QThread
{
	Q_OBJECT

public:
	MyThreadForce();
	~MyThreadForce();

    void getFpsPtr(int* ptr);

    void run();
    void getForcePtr(MyTCPForce* force);
    void getForcePtr(double* x, double*y, double*z, double*mx, double*my, double*mz);
    //传感器数据采集FIFO变量
    int index = 0;
    uint8_t pbuf[32];
    //机器人位姿数据
    double *Fx, *Fy, *Fz, *Mx, *My, *Mz;
    int* fps;

signals:
	void mess();

private:
    MyTCPForce* forcePtr = NULL;


public slots:
    void OnForceReadData();

};

#endif // MYTHREAD_H
#pragma once
