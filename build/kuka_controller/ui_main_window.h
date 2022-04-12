/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tab_manager;
    QWidget *tab_kuka;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QComboBox *cbPortName;
    QPushButton *btnSearchPort;
    QPushButton *btnOpenSerial;
    QPushButton *btnStartGetSerial;
    QPushButton *btnStopGetSerial;
    QGridLayout *gridLayout_2;
    QPushButton *btnHandeye;
    QPushButton *btnCameraCali;
    QPushButton *btnCloseDevice;
    QPushButton *btnOpenDevice;
    QPushButton *btnSaveImage;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QLineEdit *lineEdit_RX;
    QLabel *label_16;
    QLineEdit *lineEdit_RY;
    QLabel *label_17;
    QLineEdit *lineEdit_RZ;
    QLabel *label_18;
    QLineEdit *lineEdit_RA;
    QLabel *label_19;
    QLineEdit *lineEdit_RB;
    QLabel *label_20;
    QLineEdit *lineEdit_RC;
    QLabel *label_25;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_Fy;
    QLineEdit *lineEdit_Mz;
    QLabel *label_12;
    QLineEdit *lineEdit_Fx;
    QLabel *label_9;
    QLineEdit *lineEdit_Fz;
    QLineEdit *lineEdit_Mx;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_My;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_24;
    QLabel *labelCamera;
    QLabel *label_26;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_X;
    QSlider *hSlider_X;
    QLabel *label_7;
    QLineEdit *lineEdit_Y;
    QSlider *hSlider_Y;
    QLabel *label_8;
    QLineEdit *lineEdit_Z;
    QSlider *hSlider_Z;
    QLabel *label_21;
    QLineEdit *lineEdit_A;
    QSlider *hSlider_A;
    QLabel *label_22;
    QLineEdit *lineEdit_B;
    QSlider *hSlider_B;
    QLabel *label_23;
    QLineEdit *lineEdit_C;
    QSlider *hSlider_C;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLineEdit *line_port;
    QPushButton *btnOpenRobot;
    QPushButton *btnCloseRobot;
    QPushButton *btnSendPosition;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QStringLiteral("MainWindowDesign"));
        MainWindowDesign->resize(1020, 900);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QStringLiteral("tab_manager"));
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab_kuka = new QWidget();
        tab_kuka->setObjectName(QStringLiteral("tab_kuka"));
        gridLayout_8 = new QGridLayout(tab_kuka);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(tab_kuka);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        cbPortName = new QComboBox(tab_kuka);
        cbPortName->setObjectName(QStringLiteral("cbPortName"));

        gridLayout_4->addWidget(cbPortName, 0, 1, 1, 2);

        btnSearchPort = new QPushButton(tab_kuka);
        btnSearchPort->setObjectName(QStringLiteral("btnSearchPort"));

        gridLayout_4->addWidget(btnSearchPort, 1, 0, 1, 2);

        btnOpenSerial = new QPushButton(tab_kuka);
        btnOpenSerial->setObjectName(QStringLiteral("btnOpenSerial"));

        gridLayout_4->addWidget(btnOpenSerial, 1, 2, 1, 1);

        btnStartGetSerial = new QPushButton(tab_kuka);
        btnStartGetSerial->setObjectName(QStringLiteral("btnStartGetSerial"));

        gridLayout_4->addWidget(btnStartGetSerial, 2, 0, 1, 2);

        btnStopGetSerial = new QPushButton(tab_kuka);
        btnStopGetSerial->setObjectName(QStringLiteral("btnStopGetSerial"));

        gridLayout_4->addWidget(btnStopGetSerial, 2, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 3, 2, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnHandeye = new QPushButton(tab_kuka);
        btnHandeye->setObjectName(QStringLiteral("btnHandeye"));

        gridLayout_2->addWidget(btnHandeye, 3, 1, 1, 1);

        btnCameraCali = new QPushButton(tab_kuka);
        btnCameraCali->setObjectName(QStringLiteral("btnCameraCali"));

        gridLayout_2->addWidget(btnCameraCali, 3, 0, 1, 1);

        btnCloseDevice = new QPushButton(tab_kuka);
        btnCloseDevice->setObjectName(QStringLiteral("btnCloseDevice"));

        gridLayout_2->addWidget(btnCloseDevice, 0, 1, 1, 1);

        btnOpenDevice = new QPushButton(tab_kuka);
        btnOpenDevice->setObjectName(QStringLiteral("btnOpenDevice"));

        gridLayout_2->addWidget(btnOpenDevice, 0, 0, 1, 1);

        btnSaveImage = new QPushButton(tab_kuka);
        btnSaveImage->setObjectName(QStringLiteral("btnSaveImage"));

        gridLayout_2->addWidget(btnSaveImage, 1, 0, 1, 2);

        pushButton = new QPushButton(tab_kuka);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(tab_kuka);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 2, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 8, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_15 = new QLabel(tab_kuka);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        lineEdit_RX = new QLineEdit(tab_kuka);
        lineEdit_RX->setObjectName(QStringLiteral("lineEdit_RX"));

        horizontalLayout_3->addWidget(lineEdit_RX);

        label_16 = new QLabel(tab_kuka);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_3->addWidget(label_16);

        lineEdit_RY = new QLineEdit(tab_kuka);
        lineEdit_RY->setObjectName(QStringLiteral("lineEdit_RY"));

        horizontalLayout_3->addWidget(lineEdit_RY);

        label_17 = new QLabel(tab_kuka);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_3->addWidget(label_17);

        lineEdit_RZ = new QLineEdit(tab_kuka);
        lineEdit_RZ->setObjectName(QStringLiteral("lineEdit_RZ"));

        horizontalLayout_3->addWidget(lineEdit_RZ);

        label_18 = new QLabel(tab_kuka);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_3->addWidget(label_18);

        lineEdit_RA = new QLineEdit(tab_kuka);
        lineEdit_RA->setObjectName(QStringLiteral("lineEdit_RA"));

        horizontalLayout_3->addWidget(lineEdit_RA);

        label_19 = new QLabel(tab_kuka);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_3->addWidget(label_19);

        lineEdit_RB = new QLineEdit(tab_kuka);
        lineEdit_RB->setObjectName(QStringLiteral("lineEdit_RB"));

        horizontalLayout_3->addWidget(lineEdit_RB);

        label_20 = new QLabel(tab_kuka);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_3->addWidget(label_20);

        lineEdit_RC = new QLineEdit(tab_kuka);
        lineEdit_RC->setObjectName(QStringLiteral("lineEdit_RC"));

        horizontalLayout_3->addWidget(lineEdit_RC);


        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        label_25 = new QLabel(tab_kuka);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_8->addWidget(label_25, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        lineEdit_Fy = new QLineEdit(tab_kuka);
        lineEdit_Fy->setObjectName(QStringLiteral("lineEdit_Fy"));

        gridLayout_6->addWidget(lineEdit_Fy, 1, 1, 1, 1);

        lineEdit_Mz = new QLineEdit(tab_kuka);
        lineEdit_Mz->setObjectName(QStringLiteral("lineEdit_Mz"));

        gridLayout_6->addWidget(lineEdit_Mz, 5, 1, 1, 1);

        label_12 = new QLabel(tab_kuka);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_6->addWidget(label_12, 3, 0, 1, 1);

        lineEdit_Fx = new QLineEdit(tab_kuka);
        lineEdit_Fx->setObjectName(QStringLiteral("lineEdit_Fx"));

        gridLayout_6->addWidget(lineEdit_Fx, 0, 1, 1, 1);

        label_9 = new QLabel(tab_kuka);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_Fz = new QLineEdit(tab_kuka);
        lineEdit_Fz->setObjectName(QStringLiteral("lineEdit_Fz"));

        gridLayout_6->addWidget(lineEdit_Fz, 2, 1, 1, 1);

        lineEdit_Mx = new QLineEdit(tab_kuka);
        lineEdit_Mx->setObjectName(QStringLiteral("lineEdit_Mx"));

        gridLayout_6->addWidget(lineEdit_Mx, 3, 1, 1, 1);

        label_13 = new QLabel(tab_kuka);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_6->addWidget(label_13, 4, 0, 1, 1);

        label_10 = new QLabel(tab_kuka);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(tab_kuka);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        lineEdit_My = new QLineEdit(tab_kuka);
        lineEdit_My->setObjectName(QStringLiteral("lineEdit_My"));

        gridLayout_6->addWidget(lineEdit_My, 4, 1, 1, 1);

        label_14 = new QLabel(tab_kuka);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_6->addWidget(label_14, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 6, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 6, 3, 1, 1);

        label_24 = new QLabel(tab_kuka);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_8->addWidget(label_24, 5, 3, 1, 1);

        labelCamera = new QLabel(tab_kuka);
        labelCamera->setObjectName(QStringLiteral("labelCamera"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCamera->sizePolicy().hasHeightForWidth());
        labelCamera->setSizePolicy(sizePolicy);
        labelCamera->setMaximumSize(QSize(800, 600));
        labelCamera->setFrameShape(QFrame::Box);
        labelCamera->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(labelCamera, 2, 0, 5, 2);

        label_26 = new QLabel(tab_kuka);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_8->addWidget(label_26, 1, 2, 1, 2);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_6 = new QLabel(tab_kuka);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(20, 0));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_X = new QLineEdit(tab_kuka);
        lineEdit_X->setObjectName(QStringLiteral("lineEdit_X"));
        lineEdit_X->setMinimumSize(QSize(0, 0));
        lineEdit_X->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_X, 0, 1, 1, 1);

        hSlider_X = new QSlider(tab_kuka);
        hSlider_X->setObjectName(QStringLiteral("hSlider_X"));
        hSlider_X->setMinimum(1000000000);
        hSlider_X->setMaximum(1500000000);
        hSlider_X->setSingleStep(10000);
        hSlider_X->setPageStep(10000);
        hSlider_X->setValue(1000000000);
        hSlider_X->setTracking(false);
        hSlider_X->setOrientation(Qt::Horizontal);
        hSlider_X->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_X, 0, 2, 1, 1);

        label_7 = new QLabel(tab_kuka);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_7->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_Y = new QLineEdit(tab_kuka);
        lineEdit_Y->setObjectName(QStringLiteral("lineEdit_Y"));
        lineEdit_Y->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_Y, 1, 1, 1, 1);

        hSlider_Y = new QSlider(tab_kuka);
        hSlider_Y->setObjectName(QStringLiteral("hSlider_Y"));
        hSlider_Y->setSingleStep(10000);
        hSlider_Y->setPageStep(10000);
        hSlider_Y->setTracking(false);
        hSlider_Y->setOrientation(Qt::Horizontal);
        hSlider_Y->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_Y, 1, 2, 1, 1);

        label_8 = new QLabel(tab_kuka);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_7->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_Z = new QLineEdit(tab_kuka);
        lineEdit_Z->setObjectName(QStringLiteral("lineEdit_Z"));
        lineEdit_Z->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_Z, 2, 1, 1, 1);

        hSlider_Z = new QSlider(tab_kuka);
        hSlider_Z->setObjectName(QStringLiteral("hSlider_Z"));
        hSlider_Z->setMinimum(600000000);
        hSlider_Z->setMaximum(1120000000);
        hSlider_Z->setSingleStep(10000);
        hSlider_Z->setPageStep(10000);
        hSlider_Z->setTracking(false);
        hSlider_Z->setOrientation(Qt::Horizontal);
        hSlider_Z->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_Z, 2, 2, 1, 1);

        label_21 = new QLabel(tab_kuka);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_7->addWidget(label_21, 3, 0, 1, 1);

        lineEdit_A = new QLineEdit(tab_kuka);
        lineEdit_A->setObjectName(QStringLiteral("lineEdit_A"));
        lineEdit_A->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_A, 3, 1, 1, 1);

        hSlider_A = new QSlider(tab_kuka);
        hSlider_A->setObjectName(QStringLiteral("hSlider_A"));
        hSlider_A->setSingleStep(10000);
        hSlider_A->setPageStep(10000);
        hSlider_A->setTracking(false);
        hSlider_A->setOrientation(Qt::Horizontal);
        hSlider_A->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_A, 3, 2, 1, 1);

        label_22 = new QLabel(tab_kuka);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_7->addWidget(label_22, 4, 0, 1, 1);

        lineEdit_B = new QLineEdit(tab_kuka);
        lineEdit_B->setObjectName(QStringLiteral("lineEdit_B"));
        lineEdit_B->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_B, 4, 1, 1, 1);

        hSlider_B = new QSlider(tab_kuka);
        hSlider_B->setObjectName(QStringLiteral("hSlider_B"));
        hSlider_B->setSingleStep(10000);
        hSlider_B->setPageStep(10000);
        hSlider_B->setTracking(false);
        hSlider_B->setOrientation(Qt::Horizontal);
        hSlider_B->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_B, 4, 2, 1, 1);

        label_23 = new QLabel(tab_kuka);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_7->addWidget(label_23, 5, 0, 1, 1);

        lineEdit_C = new QLineEdit(tab_kuka);
        lineEdit_C->setObjectName(QStringLiteral("lineEdit_C"));
        lineEdit_C->setMaximumSize(QSize(110, 16777215));

        gridLayout_7->addWidget(lineEdit_C, 5, 1, 1, 1);

        hSlider_C = new QSlider(tab_kuka);
        hSlider_C->setObjectName(QStringLiteral("hSlider_C"));
        hSlider_C->setSingleStep(10000);
        hSlider_C->setPageStep(10000);
        hSlider_C->setTracking(false);
        hSlider_C->setOrientation(Qt::Horizontal);
        hSlider_C->setInvertedAppearance(false);
        hSlider_C->setInvertedControls(true);

        gridLayout_7->addWidget(hSlider_C, 5, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 8, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_5 = new QLabel(tab_kuka);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        line_port = new QLineEdit(tab_kuka);
        line_port->setObjectName(QStringLiteral("line_port"));

        gridLayout_5->addWidget(line_port, 0, 1, 1, 1);

        btnOpenRobot = new QPushButton(tab_kuka);
        btnOpenRobot->setObjectName(QStringLiteral("btnOpenRobot"));

        gridLayout_5->addWidget(btnOpenRobot, 1, 0, 1, 2);

        btnCloseRobot = new QPushButton(tab_kuka);
        btnCloseRobot->setObjectName(QStringLiteral("btnCloseRobot"));

        gridLayout_5->addWidget(btnCloseRobot, 2, 0, 1, 2);

        btnSendPosition = new QPushButton(tab_kuka);
        btnSendPosition->setObjectName(QStringLiteral("btnSendPosition"));

        gridLayout_5->addWidget(btnSendPosition, 3, 0, 1, 2);


        gridLayout_8->addLayout(gridLayout_5, 8, 1, 1, 1);

        tab_manager->addTab(tab_kuka, QString());

        verticalLayout_5->addWidget(tab_manager);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1020, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(hSlider_Y, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderYvalueChanged(int)));
        QObject::connect(btnSendPosition, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedSendPosition()));
        QObject::connect(btnOpenDevice, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedOpenDevice()));
        QObject::connect(hSlider_A, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderAvalueChanged(int)));
        QObject::connect(hSlider_B, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderBvalueChanged(int)));
        QObject::connect(lineEdit_Z, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineZeditingFinished()));
        QObject::connect(lineEdit_A, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineAeditingFinished()));
        QObject::connect(btnStopGetSerial, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedStopGetSerialPort()));
        QObject::connect(hSlider_Z, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderZvalueChanged(int)));
        QObject::connect(lineEdit_B, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineBeditingFinished()));
        QObject::connect(btnSearchPort, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedSearchSerialPort()));
        QObject::connect(btnCloseRobot, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedCloseRobot()));
        QObject::connect(btnSaveImage, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedSaveImage()));
        QObject::connect(btnStartGetSerial, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedStartGetSerialPort()));
        QObject::connect(btnOpenSerial, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedOpenSerialPort()));
        QObject::connect(lineEdit_X, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineXeditingFinished()));
        QObject::connect(hSlider_X, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderXvalueChanged(int)));
        QObject::connect(lineEdit_C, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineCeditingFinished()));
        QObject::connect(btnCloseDevice, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedCloseDevice()));
        QObject::connect(btnOpenRobot, SIGNAL(clicked()), MainWindowDesign, SLOT(OnBtnClickedOpenRobot()));
        QObject::connect(hSlider_C, SIGNAL(valueChanged(int)), MainWindowDesign, SLOT(OnSliderCvalueChanged(int)));
        QObject::connect(lineEdit_Y, SIGNAL(editingFinished()), MainWindowDesign, SLOT(OnLineYeditingFinished()));

        tab_manager->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "KukaController", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowDesign", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        btnSearchPort->setText(QApplication::translate("MainWindowDesign", "\346\220\234\347\264\242\344\270\262\345\217\243", Q_NULLPTR));
        btnOpenSerial->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        btnStartGetSerial->setText(QApplication::translate("MainWindowDesign", "\345\274\200\345\247\213\351\207\207\351\233\206", Q_NULLPTR));
        btnStopGetSerial->setText(QApplication::translate("MainWindowDesign", "\345\201\234\346\255\242\351\207\207\351\233\206", Q_NULLPTR));
        btnHandeye->setText(QApplication::translate("MainWindowDesign", "\346\211\213\347\234\274\346\240\207\345\256\232", Q_NULLPTR));
        btnCameraCali->setText(QApplication::translate("MainWindowDesign", "\347\233\270\346\234\272\346\240\207\345\256\232", Q_NULLPTR));
        btnCloseDevice->setText(QApplication::translate("MainWindowDesign", "\345\205\263\351\227\255\347\233\270\346\234\272", Q_NULLPTR));
        btnOpenDevice->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200\347\233\270\346\234\272", Q_NULLPTR));
        btnSaveImage->setText(QApplication::translate("MainWindowDesign", "\344\277\235\345\255\230\345\233\276\345\203\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindowDesign", "\347\233\256\346\240\207\350\257\206\345\210\253", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindowDesign", "\346\250\241\346\235\277\345\214\271\351\205\215", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindowDesign", "X\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindowDesign", "Y\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindowDesign", "Z\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindowDesign", "A\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindowDesign", "B\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindowDesign", "C\357\274\232", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindowDesign", "Kuka\346\234\272\345\231\250\344\272\272\345\275\223\345\211\215\344\275\215\345\247\277\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindowDesign", "Mx\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindowDesign", "Fx\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindowDesign", "My\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindowDesign", "Fy\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindowDesign", "Fz\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindowDesign", "Mz\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindowDesign", "\345\212\233\344\274\240\346\204\237\345\231\250\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        labelCamera->setText(QString());
        label_26->setText(QApplication::translate("MainWindowDesign", "\345\212\233\344\274\240\346\204\237\345\231\250\344\270\262\345\217\243\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindowDesign", "X:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindowDesign", "Y:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindowDesign", "Z:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindowDesign", "A:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindowDesign", "B:", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindowDesign", "C:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowDesign", "\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        line_port->setText(QApplication::translate("MainWindowDesign", "59152", Q_NULLPTR));
        btnOpenRobot->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200\346\234\272\345\231\250\344\272\272\350\277\236\346\216\245", Q_NULLPTR));
        btnCloseRobot->setText(QApplication::translate("MainWindowDesign", "\346\226\255\345\274\200\346\234\272\345\231\250\344\272\272\350\277\236\346\216\245", Q_NULLPTR));
        btnSendPosition->setText(QApplication::translate("MainWindowDesign", "\345\217\221\351\200\201\346\234\272\345\231\250\344\272\272\347\233\256\346\240\207\344\275\215\347\275\256", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_kuka), QApplication::translate("MainWindowDesign", "Kuka\346\216\247\345\210\266\351\241\265", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "\351\200\211\351\241\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
