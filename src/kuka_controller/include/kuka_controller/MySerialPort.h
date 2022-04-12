#pragma once
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>
#include <qdebug.h>
#include <QMessageBox>

class MySerialPort
{
public:
	MySerialPort();
	QStringList GetPortNameList();
	int Open(QString portName);
	void Close();

public:
	QSerialPort* MySerial;
	QStringList portNameList;
    void sendInfo(QString& info);
    void sendInfo(char* info, int len);
    char convertCharToHex(char ch);
    void convertStringToHex(QString& str, QByteArray& byteData);
    int32_t bit8Tobit32(uint8_t* change_data);
	uint16_t crc_cal_by_byte(unsigned char* ptr, unsigned char len);

    void startGrab();
    void stopGrab();
};

