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
    m_serialPort.setBaudRate(QSerialPort::Baud57600);
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

void ApplicationData::onWifitestClicked()
{
    m_serialPort.write(QString("AT+WSCAN\r\n").toLatin1());
}

void ApplicationData::onWifiDebugClicked()
{
    m_serialPort.write(QString("+++").toLatin1());

}

void ApplicationData::onClearClicked()
{
    receiveString="";
    engine->rootContext()->setContextProperty("receiveTextAreaString","");
}

void ApplicationData::onActivated(int index)
{
    qDebug()<<"onActivated"<<index;
    serial_combox_index=index;
}

void ApplicationData::onReadyRead()
{

    QByteArray byteArry=m_serialPort.readAll();
    QString readString=QString(byteArry);
    receiveString=receiveString+readString;

    if(receiveString.compare("a")==0)
    {
        m_serialPort.write(QString("a").toLatin1());
        qDebug()<<"成功接收到数据";
    }
    qDebug()<<receiveString;

    engine->rootContext()->setContextProperty("receiveTextAreaString",receiveString);

    if(receiveString.startsWith("AT+")){
        qDebug()<<"接收到回复AT指令";
        if(receiveString.startsWith("AT+WSCAN")){
            qDebug()<<"AT指令发送成功";
        }
    }
    QRegExp atRegExp("AT+WSCAN");
    if(1){

        QRegExp mRegExp("(\\d+)%,([^,]*),(([0-9a-fA-F][0-9a-fA-F]:){5}[^,]*),(\\d+),");

        int regIndex=0;
        QStringList wifiSSIDList;
        //创建一个wifi合集

        QString wifiRSSI,wifiSSID,wifiEncryption;
        while ((regIndex = mRegExp.indexIn(receiveString, regIndex)) != -1) {
            regIndex += mRegExp.matchedLength();
            wifiRSSI=mRegExp.cap(1);
            qDebug()<<"信号强度:"<<wifiRSSI;
            wifiSSID=mRegExp.cap(2);
            qDebug()<<"WIFI名称:"<<wifiSSID;
            if(wifiSSID.startsWith("0x")) continue;
            wifiList.append(new wifiData(wifiSSID,wifiRSSI.toInt()));
            wifiSSIDList.append(wifiSSID);
            qDebug()<<"MAC地址:"<<mRegExp.cap(3);
            qDebug()<<"加密方式:"<<mRegExp.cap(6);

        }



        engine->rootContext()->setContextProperty("mymodel",QVariant::fromValue(wifiList));
    }




}

void ApplicationData::onCurrentIndexChanged(int index)
{
    qDebug()<<"当前界面"<<index;
}


