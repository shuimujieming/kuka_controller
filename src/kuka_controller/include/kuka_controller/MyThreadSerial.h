#ifndef MYTHREADSERIAL_H
#define MYTHREADSERIAL_H
#include "QThread"


#include <vector>  
#include <string>  
#include <algorithm>  
#include <iostream>  
#include <iterator>  
#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  

#include "MySerialPort.h"


class MyThreadSerial :public QThread
{
	Q_OBJECT

public:
	MyThreadSerial();
	~MyThreadSerial();

	void run();
    void getSerialPtr(MySerialPort* serial);
    void getForcePtr(double* x, double*y, double*z, double*mx, double*my, double*mz);

    void getFpsPtr(int* ptr);

    //传感器数据采集FIFO变量
    int index = 0;
    uint8_t pbuf[32];
    //六维力传感器数据
    double *Fx, *Fy, *Fz, *Mx, *My, *Mz;
    int* fps;

signals:
	void mess();

private:
    MySerialPort* serialPtr = NULL;


public slots:
    void OnSerialReadData();

};

#endif
