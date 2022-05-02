/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date April 2022
 **/
/*****************************************************************************
** Includes
*****************************************************************************/
//qt gui
#include <QtGui>
//message box
#include <QMessageBox>
//std io
#include <iostream>
#include "../include/kuka_controller/main_window.hpp"


using namespace Qt;
using namespace std;
/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

//
MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , controlnode(argc,argv)
    , forcedatanode(argc,argv)
    , positiondatanode(argc,argv)
{
    //UI对象初始化
     ui.setupUi(this);

     //界面控件初始化
     UiInit();

     //线程实例化
     myThreadCamera = new MyThread;
     myThreadTCP    = new MyThreadTCP;
     myThreadForce  = new MyThreadForce;

     //初始化Image
     myCameraImage = new cv::Mat();
     //初始化TCP成员
     myRoboTCP = new MyTCP();
     //
     myForceTCP   = new MyTCPForce();

     //提前搜索一次串口
     OnBtnClickedSearchSerialPort();

     //控件数据显示更新定时器初始化
     timerShow = new QTimer(this);
     timerShow->start(25);

     //数据更新FPS
     UpdateFpsTimer = new QTimer(this);


     forcedatanode.init();
     forcedatanode.getForcePtr(&Fx,&Fz,&Fy,&Mx,&My,&Mz);

     positiondatanode.init();
     positiondatanode.getPositionPtr(&X,&Y,&Z,&A,&B,&C);

     controlnode.init();
     controlnode.getTCPPtr(myRoboTCP);

     //信号槽初始化
     ConnectInit();
}

MainWindow::~MainWindow() {}
void MainWindow::ConnectInit()
{
    //查看当前版本qt库
    //connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
    //关联机械臂控制节点槽函数
    connect(&controlnode, SIGNAL(sendRobot(float,float,float,float,float,float)), this, SLOT(ctrlRobot(float,float,float,float,float,float)));
    //数据更新显示
    connect(timerShow, SIGNAL(timeout()), this, SLOT(OnUIShowUpdate()));
    //数据更新FPS
    connect(UpdateFpsTimer, SIGNAL(timeout()), this, SLOT(OnUpdateDataFps()));
    //连接信号与槽函数
    //相机图片获取与显示
    connect(myThreadCamera, SIGNAL(Display(const cv::Mat*)), this, SLOT(display_myImage(const cv::Mat*)));
}
void MainWindow::UiInit()
{
    //按钮使能初始化
     //开关相机
     ui.btnCloseDevice->setEnabled(false);
     ui.btnOpenDevice->setEnabled(true);
     //相机保存照片以及标定
     ui.btnSaveImage->setEnabled(false);
     ui.btnCameraCali->setEnabled(false);
     ui.btnHandeye->setEnabled(false);
     //机器人控制
     ui.btnSendPosition->setEnabled(false);
     ui.btnOpenRobot->setEnabled(true);
     ui.btnCloseRobot->setEnabled(false);

     //串口数据采集
     ui.btnStartGetSerial->setEnabled(false);
     ui.btnStopGetSerial->setEnabled(false);

    //滑动条值域设置
    {
        ui.hSlider_X->setMaximum(1500 * 1000000);
        ui.hSlider_X->setMinimum(1000 * 1000000);

        ui.hSlider_Y->setMaximum(400 * 1000000);
        ui.hSlider_Y->setMinimum(-550 * 1000000);

        ui.hSlider_Z->setMaximum(1120 * 1000000);
        ui.hSlider_Z->setMinimum(600 * 1000000);

        ui.hSlider_A->setMaximum(150 * 1000000);
        ui.hSlider_A->setMinimum(-150 * 1000000);

        ui.hSlider_B->setMaximum(30 * 1000000);
        ui.hSlider_B->setMinimum(-50 * 1000000);

        ui.hSlider_C->setMaximum(180 * 1000000);
        ui.hSlider_C->setMinimum(-180 * 1000000);
    }

     //图像处理按钮
     ui.btnModelMatch->setEnabled(false);
     ui.btnGoalDIst->setEnabled(false);
}
void MainWindow::closeEvent(QCloseEvent *event)
{
	QMainWindow::closeEvent(event);
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About KukaController"),tr("<h2>KukaController 1.0</h2><p>Copyright shuimujieming</p><p>此程序用于Kuka机械臂装配项目的相关操作</p>"));
}
//滑动条X值改变槽函数
void MainWindow::OnSliderXvalueChanged(int value)
{
    ui.lineEdit_X->setText(QString::number(value / 1000000.0 ,'f', 6));
    //第一次接收到的数据不做回传处理
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//滑动条Y值改变槽函数
void MainWindow::OnSliderYvalueChanged(int value)
{
    ui.lineEdit_Y->setText(QString::number(value / 1000000.0, 'f', 6));
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//滑动条Z值改变槽函数
void MainWindow::OnSliderZvalueChanged(int value)
{
    ui.lineEdit_Z->setText(QString::number(value / 1000000.0, 'f', 6));
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//滑动条A值改变槽函数
void MainWindow::OnSliderAvalueChanged(int value)
{
    ui.lineEdit_A->setText(QString::number(value / 1000000.0, 'f', 6));
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//滑动条B值改变槽函数
void MainWindow::OnSliderBvalueChanged(int value)
{
    ui.lineEdit_B->setText(QString::number(value / 1000000.0, 'f', 6));
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//滑动条C值改变槽函数
void MainWindow::OnSliderCvalueChanged(int value)
{
    ui.lineEdit_C->setText(QString::number(value / 1000000.0, 'f', 6));
    static bool isFirstChanged = false;
    if (isFirstChanged)
    {
        SendPosition();
    }
    isFirstChanged = true;
}
//编辑框X输入完成槽函数
void MainWindow::OnLineXeditingFinished()
{
  /* 按下enter键处理的事 */
        if (ui.lineEdit_X->hasFocus())
        {
            if (ui.lineEdit_X->text().toDouble() * 1000000 > ui.hSlider_X->maximum() || ui.lineEdit_X->text().toDouble() * 1000000 < ui.hSlider_X->minimum())
            {
                //超出范围
                QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
            }
            else
            {
                //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
                ui.hSlider_X->setValue(ui.lineEdit_X->text().toDouble() * 1000000);
            }
        }
}
//编辑框Y输入完成槽函数
void MainWindow::OnLineYeditingFinished()
{
    /* 按下enter键处理的事 */
    if (ui.lineEdit_Y->hasFocus())
    {
        if (ui.lineEdit_Y->text().toDouble() * 1000000 > ui.hSlider_Y->maximum() || ui.lineEdit_Y->text().toDouble() * 1000000 < ui.hSlider_Y->minimum())
        {
            //超出范围
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
        }
        else
        {
            //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
            ui.hSlider_Y->setValue(ui.lineEdit_Y->text().toDouble() * 1000000);
        }
    }
}
//编辑框Z输入完成槽函数
void MainWindow::OnLineZeditingFinished()
{
    /* 按下enter键处理的事 */
    if (ui.lineEdit_Z->hasFocus())
    {
        if (ui.lineEdit_Z->text().toDouble() * 1000000 > ui.hSlider_Z->maximum() || ui.lineEdit_Z->text().toDouble() * 1000000 < ui.hSlider_Z->minimum())
        {
            //超出范围
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
        }
        else
        {
            //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
            ui.hSlider_Z->setValue(ui.lineEdit_Z->text().toDouble() * 1000000);
        }
    }
}
//编辑框A输入完成槽函数
void MainWindow::OnLineAeditingFinished()
{
    /* 按下enter键处理的事 */
    if (ui.lineEdit_A->hasFocus())
    {
        if (ui.lineEdit_A->text().toDouble() * 1000000 > ui.hSlider_A->maximum() || ui.lineEdit_A->text().toDouble() * 1000000 < ui.hSlider_A->minimum())
        {
            //超出范围
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
        }
        else
        {
            //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
            ui.hSlider_A->setValue(ui.lineEdit_A->text().toDouble() * 1000000);
        }
    }
}
//编辑框B输入完成槽函数
void MainWindow::OnLineBeditingFinished()
{
    /* 按下enter键处理的事 */
    if (ui.lineEdit_B->hasFocus())
    {
        if (ui.lineEdit_B->text().toDouble() * 1000000 > ui.hSlider_B->maximum() || ui.lineEdit_B->text().toDouble() * 1000000 < ui.hSlider_B->minimum())
        {
            //超出范围
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
        }
        else
        {
            //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
            ui.hSlider_B->setValue(ui.lineEdit_B->text().toDouble() * 1000000);
        }
    }
}
//编辑框C输入完成槽函数
void MainWindow::OnLineCeditingFinished()
{
    /* 按下enter键处理的事 */
    if (ui.lineEdit_C->hasFocus())
    {
        if (ui.lineEdit_C->text().toDouble() * 1000000 > ui.hSlider_C->maximum() || ui.lineEdit_C->text().toDouble() * 1000000 < ui.hSlider_C->minimum())
        {
            //超出范围
            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请输入正确的值！"), QMessageBox::Yes);
        }
        else
        {
            //字符串转小数存在精度问题，所以这里使用Double而不是float，用float会丢失精确度
            ui.hSlider_C->setValue(ui.lineEdit_C->text().toDouble() * 1000000);
        }
    }
}

//打开机器人TCP按钮槽函数
void MainWindow::OnBtnClickedOpenRobot()
{
    if (myRoboTCP->OpenTCP(ui.line_port->text().toInt()) == 0)
    {
        connect(myRoboTCP->MyTCPServer, SIGNAL(newConnection()), this, SLOT(OnServerNewConnection()));
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("打开TCP监听中"), QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("打开机器人失败"), QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//关闭机器人TCP按钮槽函数
void MainWindow::OnBtnClickedCloseRobot()
{
    myRoboTCP->CloseTCP();
}



//发送机器人目标位置
int MainWindow::SendPosition()
{
    string x = ui.lineEdit_X->text().toStdString();
    string y = ui.lineEdit_Y->text().toStdString();
    string z = ui.lineEdit_Z->text().toStdString();
    string a = ui.lineEdit_A->text().toStdString();
    string b = ui.lineEdit_B->text().toStdString();
    string c = ui.lineEdit_C->text().toStdString();

    string sendData;
    sendData = "<Sensor><Read><xyzabc X=\"" + x + "\" Y=\"" + y + "\" Z=\"" + z + "\" A=\"" + a + "\" B=\"" + b + "\" C=\"" + c + "\"></xyzabc></Read><WaitRecv>998</WaitRecv></Sensor>";

    myRoboTCP->SendData(sendData);

    {
        cout << "发送机械臂目标位置：" << "X = \"" + x + "\" Y=\"" + y + "\" Z=\"" + z + "\" A=\"" + a + "\" B=\"" + b + "\" C=\"" + c << endl;
    }

    return 0;
}

void MainWindow::ctrlRobot(float x,float y, float z,float a,float b,float c)
{
    myRoboTCP->CtrlRobot(x,y,z,a,b,c);
}

//发送机器人目标位置按钮槽函数
void MainWindow::OnBtnClickedSendPosition()
{
    SendPosition();
}

//服务端发现新连接槽函数
void MainWindow::OnServerNewConnection()
{
    //获取客户端连接
    myRoboTCP->MyTCPSocket = myRoboTCP->MyTCPServer->nextPendingConnection();

    if (!myRoboTCP->MyTCPSocket)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未正确获取客户端连接！"));
        return;
    }
    else
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("成功获取客户端连接！"));
        ui.btnOpenRobot->setEnabled(false);
        ui.btnCloseRobot->setEnabled(true);
        ui.btnSendPosition->setEnabled(true);

        myThreadTCP->getTCPPtr(myRoboTCP);
        myThreadTCP->getPositionPtr(&X,&Y,&Z,&A,&B,&C);
//        myThreadTCP->start();

        connect(myRoboTCP->MyTCPSocket, SIGNAL(disconnected()), this, SLOT(OnServerDisConnection()));
    }
}

//服务端断开连接槽函数
void MainWindow::OnServerDisConnection()
{
    if (myRoboTCP->CloseTCP() == 0)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("与客户端断开连接！"));

        ui.btnOpenRobot->setEnabled(true);
        ui.btnCloseRobot->setEnabled(false);
        ui.btnSendPosition->setEnabled(false);

        myThreadTCP->terminate();
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("断开失败！"));
    }
    return;
}


//打开相机设备
int MainWindow::OpenDevices()
{
    int nRet = MV_OK;

    MV_CC_DEVICE_INFO_LIST m_stDevList = { 0 };
    nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);
    // ch:枚举子网内所有设备,相机设备数量
    if (MV_OK != nRet)
    {
        printf("Enum Devices fail! nRet [0x%x]\n", nRet);
    }

    // 创建相机指针对象
    if(m_stDevList.nDeviceNum > 0)
    {
        MyCamera = new CMvCamera;
        // 相机对象初始化
        MyCamera->m_pBufForDriver = NULL;
        MyCamera->m_pBufForSaveImage = NULL;
        MyCamera->m_nBufSizeForDriver = 0;
        MyCamera->m_nBufSizeForSaveImage = 0;
        MyCamera->m_nTLayerType = m_stDevList.pDeviceInfo[0]->nTLayerType;

        nRet = MyCamera->Open(m_stDevList.pDeviceInfo[0]); //打开相机

        if (nRet != MV_OK)
        {
            return -1;
        }

        //设置触发模式0（不开启触发模式）
        MyCamera->setTriggerMode(0);


        //获取相机帧率上限
        MVCC_FLOATVALUE pstValue;
        MV_CC_GetGain(MyCamera->m_hDevHandle, &pstValue);

        //设置相机图像输出格式为RGB8
        nRet = MV_CC_SetPixelFormat(MyCamera->m_hDevHandle, PixelType_Gvsp_RGB8_Packed);
        if (MV_OK != nRet)
        {
            printf("set PixelFormat fail! nRet [0x%x]\n", nRet);
        }
        // 设置相机常见参数
        //设置相机帧率最高
        nRet = MV_CC_SetFrameRate(MyCamera->m_hDevHandle, pstValue.fMax);
        if (MV_OK != nRet)
        {
            printf("set FrameRate fail! nRet [0x%x]\n", nRet);
        }
        //设置曝光时间
        nRet = MV_CC_SetExposureTime(MyCamera->m_hDevHandle, 100000.f);
        if (MV_OK != nRet)
        {
            printf("set Exposure Time fail! nRet [0x%x]\n", nRet);
        }

        // 保存相机参数
        printf("保存相机参数中。。。\n");

        nRet = MV_CC_FeatureSave(MyCamera->m_hDevHandle, "FeatureFile.ini");
        if (MV_OK != nRet)
        {
            printf("Save Feature fail! nRet [0x%x]\n", nRet);
        }
        std::cout << "相机参数保存完成" << std::endl;

        //开启相机采集
        MyCamera->StartGrabbing();
        myThreadCamera->getCameraPtr(MyCamera);
        myThreadCamera->getImagePtr(myCameraImage);

        if (!myThreadCamera->isRunning())
        {
            myThreadCamera->start();
            MyCamera->ReadBuffer(*myCameraImage);
        }

        ui.btnSaveImage->setEnabled(true);
    }
    else
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未找到相机设备！"), QMessageBox::Ok, QMessageBox::NoButton);
        return -1;
    }

    return 0;
}
//关闭相机设备
int MainWindow::CloseDevices()
{
    int nRet;
        // 关闭线程、相机
        if (myThreadCamera->isRunning())
        {
            myThreadCamera->requestInterruption();
            myThreadCamera->wait();
            MyCamera->StopGrabbing();
            nRet = MyCamera->Close();
            if (nRet != MV_OK)
            {
                return -1;
            }
        }

    // ch:关闭之后再枚举一遍 | en:Enumerate after close
    memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));    // ch:初始化设备信息列表
    int devices_num = MV_OK;
    devices_num = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);           // ch:枚举子网内所有设备,相机设备数量
    return 0;
}

//打开相机按钮槽函数
void MainWindow::OnBtnClickedOpenDevice()
{
    int Ret = OpenDevices();
    if (!Ret)
    {
        ui.btnOpenDevice->setEnabled(false);
        ui.btnCloseDevice->setEnabled(true);
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机打开成功"), QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机打开失败"),QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//关闭相机按钮槽函数
void MainWindow::OnBtnClickedCloseDevice()
{
    int Ret = CloseDevices();
    if (!Ret)
    {
        ui.btnOpenDevice->setEnabled(true);
        ui.btnCloseDevice->setEnabled(false);
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机关闭成功"), QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机关闭失败"), QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//保存照片按钮槽函数
void MainWindow::OnBtnClickedSaveImage()
{
    char filename[100] = { 0 };
    sprintf(filename, "%f,%f,%f,%f,%f,%f.jpg", X, Y, Z, A, B, C);
    cv::imwrite(filename, *myCameraImage);
    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("保存成功"), QMessageBox::Ok, QMessageBox::NoButton);
}

//显示图片槽函数
void MainWindow::display_myImage(const cv::Mat* imagePtr)
{
    //转换图像格式BGR2RGB
    cv::Mat Image_RGB;
    cv::cvtColor(*imagePtr, Image_RGB, CV_BGR2RGB);
    QImage QmyImage;
    //转换成QT图像格式
    QmyImage = QImage((const unsigned char*)(Image_RGB.data), Image_RGB.cols, Image_RGB.rows, QImage::Format_RGB888);
    //将图片等比例缩放为显示窗口大小
    QmyImage = (QmyImage).scaled(ui.labelCamera->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //显示在控件上
    ui.labelCamera->setPixmap(QPixmap::fromImage(QmyImage));
}

//搜索串口按钮槽函数
void MainWindow::OnBtnClickedSearchSerialPort()
{
    QStringList nameList;
    //获取设备列表
    nameList = myserialPort->GetPortNameList();
    //清空combox列表
    ui.cbPortName->clear();
    //添加属性
    foreach(const QString & info, nameList)
    {
        ui.cbPortName->addItem(info);
    }
}
//打开串口槽函数
void MainWindow::OnBtnClickedOpenSerialPort()
{
    //根据标签名称对应功能
    if (ui.btnOpenSerial->text() == QString::fromLocal8Bit("打开串口"))
    {
        //TCP通信方式
        if(myForceTCP->OpenTCP("192.168.1.66",8080) == 0)
        {
            //打开TCP线程 提供TCP指针
            myThreadForce->getForcePtr(myForceTCP);
            myThreadForce->getForcePtr(&Fx,&Fy,&Fz,&Mx,&My,&Mz);
            myThreadForce->getFpsPtr(&UpdateFPS);
            myThreadForce->start();

            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("串口打开成功"), QMessageBox::Ok, QMessageBox::NoButton);
            ui.btnOpenSerial->setText(QString::fromLocal8Bit("关闭串口"));
            ui.btnStartGetSerial->setEnabled(true);
            ui.btnStopGetSerial->setEnabled(true);
        }
        else
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("串口打开失败"), QMessageBox::Ok, QMessageBox::NoButton);
        }
    }
    else
    {
        myForceTCP->CloseTCP();
        //myThreadForce->terminate();


        ui.btnOpenSerial->setText(QString::fromLocal8Bit("打开串口"));
        ui.btnStartGetSerial->setEnabled(false);
        ui.btnStopGetSerial->setEnabled(false);
    }
}
//开启采集数据按钮槽函数
void MainWindow::OnBtnClickedStartGetSerialPort()
{
    myForceTCP->startGrab();
    UpdateFpsTimer->start(1000);
}
//停止采集数据按钮槽函数
void MainWindow::OnBtnClickedStopGetSerialPort()
{
    myForceTCP->stopGrab();
    UpdateFpsTimer->stop();
}
//数据FPS更新显示
void MainWindow::OnUpdateDataFps()
{
    cout<<"ForceData Update Fps is : "<<UpdateFPS << endl;
    UpdateFPS = 0;
}
//更新UI界面机器人数据
void MainWindow::OnUIShowUpdate()
{
    ui.lineEdit_Fx->setText(QByteArray::fromStdString(to_string(Fx)));
    ui.lineEdit_Fy->setText(QByteArray::fromStdString(to_string(Fy)));
    ui.lineEdit_Fz->setText(QByteArray::fromStdString(to_string(Fz)));
    ui.lineEdit_Mx->setText(QByteArray::fromStdString(to_string(Mx)));
    ui.lineEdit_My->setText(QByteArray::fromStdString(to_string(My)));
    ui.lineEdit_Mz->setText(QByteArray::fromStdString(to_string(Mz)));

    ui.lineEdit_RX->setText(QByteArray::fromStdString(to_string(X)));
    ui.lineEdit_RY->setText(QByteArray::fromStdString(to_string(Y)));
    ui.lineEdit_RZ->setText(QByteArray::fromStdString(to_string(Z)));
    ui.lineEdit_RA->setText(QByteArray::fromStdString(to_string(A)));
    ui.lineEdit_RB->setText(QByteArray::fromStdString(to_string(B)));
    ui.lineEdit_RC->setText(QByteArray::fromStdString(to_string(C)));
}
