#include "../include/kuka_controller/MyThread.h"


MyThread::MyThread()
{
}

MyThread::~MyThread()
{
    terminate();
    if (cameraPtr != NULL)
    {
        delete cameraPtr;
    }
    if (imagePtr != NULL)
    {
        delete imagePtr;
    }
}

void MyThread::getCameraPtr(CMvCamera* camera)
{
    cameraPtr = camera;
}

void MyThread::getImagePtr(cv::Mat* image)
{
    imagePtr = image;
}

void MyThread::run()
{
    if (cameraPtr == NULL){
        return;
    }

    if (imagePtr == NULL){
        return;
    }

    while (!isInterruptionRequested())
    {
        cameraPtr->ReadBuffer(*imagePtr);
        emit Display(imagePtr);//·¢ËÍÐÅºÅ
        msleep(30);
    }
}
