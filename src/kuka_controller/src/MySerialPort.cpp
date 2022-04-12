#include "../include/kuka_controller/MySerialPort.h"

MySerialPort::MySerialPort()
{
    MySerial = new QSerialPort();
}

//获取串口列表
QStringList MySerialPort::GetPortNameList()
{
    QStringList serialPortName;

    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
    {
        serialPortName << info.portName();
//        qDebug() << "serialPortName:" << info.portName();
    }
    return serialPortName;
}
//打开串口
int MySerialPort::Open(QString portName)
{
    MySerial->setPortName(portName);
    //波特率设置——1500000
    MySerial->setBaudRate(1500000, QSerialPort::AllDirections);
    //数据位设置——8位
    MySerial->setDataBits(QSerialPort::Data8);
    //设置奇偶校验位——偶校验
    MySerial->setParity(QSerialPort::EvenParity);
    //设置停止位——1位
    MySerial->setStopBits(QSerialPort::OneStop);
    //设置流控制——无流控制
    MySerial->setFlowControl(QSerialPort::NoFlowControl);

    //打开串口
    if (!MySerial->open(QIODevice::ReadWrite))
    {
        return -1;
    }

    return 0;
}
//关闭串口
void MySerialPort::Close()
{
    if (MySerial->isOpen())
    {
        MySerial->close();
    }
}

//8位合成32位数据
int32_t MySerialPort::bit8Tobit32(uint8_t* change_data)
{
    union
    {
        int32_t f;
        uint8_t byte[4];
    }u32val;
    u32val.byte[0] = change_data[0];
    u32val.byte[1] = change_data[1];
    u32val.byte[2] = change_data[2];
    u32val.byte[3] = change_data[3];
    return u32val.f;
}

//QString转16进制
void MySerialPort::convertStringToHex(QString& str, QByteArray& byteData)
{
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len / 2);
    char lstr, hstr;
    for (int i = 0; i < len; )
    {
        //char lstr,
        //高位数据
        //0xfe
        //f
        hstr = str[i].toLatin1(); //Latin1代表ASCII，Local8Bit代表unicode
        if (hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if (i >= len)
            break;
        //低位数据
        //0xfe
        //e
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if ((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            //转位0xfe，f左移四位即*16
            hexdata = hexdata * 16 + lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

//char转16进制
char MySerialPort::convertCharToHex(char ch)
{
    /*
    0x30等于十进制的48，48也是0的ASCII值，，
    */
    //字符0-9转为十六进制0-9
    if ((ch >= '0') && (ch <= '9'))
        return ch - 0x30;
    //字符a-f，转十六进值a-f，即10-15
    else if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;
    else if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;
    else return (-1);
}


//发送字符数据
void MySerialPort::sendInfo(char* info, int len) {

    for (int i = 0; i < len; ++i)
    {
        printf("0x%x\n", info[i]);
    }
    MySerial->write(info, len);
}
//发送16进制数据
void MySerialPort::sendInfo(QString& info) {

    QByteArray sendBuf;
    if (info.contains(" "))
    {
        info.replace(QString(" "), QString(""));//把空格去掉
    }
    convertStringToHex(info, sendBuf); //把QString 转换 为 hex

    MySerial->write(sendBuf);

}
/* CRC字节表 */
unsigned int crc_ta_8[256] = {
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};
//CRC16校验
//CRC校验范围为有效数据范围（设备地址~内容）
uint16_t MySerialPort::crc_cal_by_byte(unsigned char* ptr, unsigned char len)
{
    unsigned short crc = 0xffff;
    while (len-- != 0)
    {
        unsigned int high = (unsigned int)(crc / 256);
        crc <<= 8;
        crc ^= crc_ta_8[high ^ *ptr];
        ptr++;
    }
    return crc;
}

void MySerialPort::startGrab()
{
    //发送数据
    //16进制
    //连续采集
    QString sendBuf = QString("f6 6f 03 00 00 02 de ec 6f f6");;
    //发送串口数据
    sendInfo(sendBuf);
}

void MySerialPort::stopGrab()
{
    //发送数据
    //16进制
    //发50个0x00阻塞传感器发送
    QString sendBuf = QString("00 00 00 00 00 00 00 00 00 00");
    for (int i = 0; i < 5; i++)
    {
        //发送串口数据
        sendInfo(sendBuf);
    }
    //延时200ms后发送停止采集命令
    //实测效果不好，去掉延时
    //sleep(100);
    sendBuf = QString("f6 6f 03 00 00 03 ff fc 6f f6");
    sendInfo(sendBuf);
}
