/**
 * @file /include/kuka_controller/main_window.hpp
 *
 * @brief Qt based gui for kuka_controller.
 *
 * @date April 2022
 **/
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"

#include "controlnode.h"
#include "forcedatanode.h"
#include "positionnode.h"

#include "MvCamera.h"
#include "MyThread.h"
#include "MyTCP.h"
#include "MySerialPort.h"
#include "MyThreadSerial.h"
#include "MyThreadTCP.h"

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void closeEvent(QCloseEvent *event); // Overloaded function

private:
    Ui::MainWindowDesign ui;
    ControlNode controlnode;
    ForcedataNode forcedatanode;
    PositiondataNode positiondatanode;

    QTimer* timerShow;
    QTimer* UpdateFpsTimer;

    //相机操作对象
    CMvCamera* MyCamera;
    //相机设备列表
    MV_CC_DEVICE_INFO_LIST m_stDevList;
    cv::Mat* myCameraImage = new cv::Mat();

    //机械臂六自由度坐标
    double X,Y,Z,A,B,C ;
    //六维力传感器数据
    double Fx, Fy, Fz, Mx, My, Mz;

    MyThread* myThreadCamera = NULL;
    MyThreadSerial* myThreadSerial = NULL;
    MyTCP* myRoboTCP = NULL;
    MyThreadTCP* myThreadTCP = NULL;

    MySerialPort* myserialPort = NULL;
    int UpdateFPS = 0;
public:
    void ConnectInit();
    void UiInit();
    //打开关闭相机
    int OpenDevices();
    int CloseDevices();
    int SendPosition();
private slots:
    void on_actionAbout_triggered();

    //按钮槽函数
    void OnBtnClickedOpenDevice();
    void OnBtnClickedCloseDevice();
    void OnBtnClickedSaveImage();

    void OnBtnClickedOpenRobot();
    void OnBtnClickedCloseRobot();
    void OnBtnClickedSendPosition();

    //显示图片的槽函数
    void display_myImage(const cv::Mat* imagePtr);

    //TCP服务端相关槽函数
    void OnServerNewConnection();
    void OnServerDisConnection();

    //滑动条槽函数
    void OnSliderXvalueChanged(int value);
    void OnSliderYvalueChanged(int value);
    void OnSliderZvalueChanged(int value);
    void OnSliderAvalueChanged(int value);
    void OnSliderBvalueChanged(int value);
    void OnSliderCvalueChanged(int value);

    //编辑框槽函数
    void OnLineXeditingFinished();
    void OnLineYeditingFinished();
    void OnLineZeditingFinished();
    void OnLineAeditingFinished();
    void OnLineBeditingFinished();
    void OnLineCeditingFinished();

    void OnBtnClickedSearchSerialPort();
    void OnBtnClickedOpenSerialPort();
    void OnBtnClickedStartGetSerialPort();
    void OnBtnClickedStopGetSerialPort();

    void OnUpdateDataFps();
    void OnUIShowUpdate();

signals:
    void rosShutdown();
};

#endif // MAIN_WINDOW_H
