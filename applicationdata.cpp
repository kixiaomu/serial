#include "applicationdata.h"

ApplicationData::ApplicationData()
{
    qDebug()<<"application is construct";
    //connect(m_page1,SIGNAL(scanClicked),this,SLOT(onScanClicked()))

}

QStringList ApplicationData::getAllSerialPortName()
{
    QStringList serialNameStringList;
    QList<QString> serialPortNameList;
    serialPortInfoList=QSerialPortInfo::availablePorts();
    foreach (QSerialPortInfo serialPortInfo,serialPortInfoList ) {
        serialNameStringList.append(serialPortInfo.portName());
    }
    return serialNameStringList;
}


void ApplicationData::onScanClicked()
{
    QString str="111,222,333";
    qDebug()<<"64546";
    engine->rootContext()->setContextProperty("comboxModel",QVariant::fromValue(getAllSerialPortName()));
    //qDebug<<(new QStringList()<<"123456"<<"11111");
    //engine.rootContext()->setContextProperty("comboxModel",QVariant::fromValue(new QStringList()<<"111"<<"222"));
}

void ApplicationData::onListenClicked()
{
    qDebug()<<"开始监听,当前值:"<<serial_combox_index;
    m_serialPort.setPort(serialPortInfoList.at(serial_combox_index));
    m_serialPort.setBaudRate(QSerialPort::Baud115200);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setStopBits(QSerialPort::OneStop);
    m_serialPort.setFlowControl(QSerialPort::NoFlowControl);
    if(!m_serialPort.open(QIODevice::ReadWrite))
    {
        if(m_serialPort.error()==QSerialPort::PermissionError)
        {
            qDebug()<<"串口已被占用";\
            return;
        }
        else if(m_serialPort.error()==QSerialPort::OpenError)
        {
            qDebug()<<"串口已打开";
            return;
        }


    }
    connect(&m_serialPort,QSerialPort::readyRead,this,&onReadyRead);
}

void ApplicationData::onActivated(int index)
{
    qDebug()<<"onActivated"<<index;
    serial_combox_index=index;
}
QString receiveString;
void ApplicationData::onReadyRead()
{

    QByteArray byteArry=m_serialPort.readAll();
    receiveString=receiveString+QString(byteArry);
    qDebug()<<QString(byteArry);
    engine->rootContext()->setContextProperty("receiveTextAreaString",receiveString);

}

