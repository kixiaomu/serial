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
/*
"AT+WSCAN\r\n\r+ok=\n\rRSSI,SSID,BSSID,Channel,Encryption,Authentication\n\r100%,YCF-EE,c4:36:55:0a:c8:bb,13,AES,WPA2PSK,\n\r76%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:da:db,11,NONE,OPEN,\n\r68%,TOTOLINK_a9f044,f4:28:53:a9:f0:44,1,AES,WPA2PSK,\n\r52%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:9b,6,NONE,OPEN,\n\r60%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:6f,11,NONE,OPEN,\n\r42%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:97,11,NONE,OPEN,\n\r39%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:4f,1,NONE,OPEN,\n\r37%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:a7,11,NONE,OPEN,\n\r23%,ChinaNet-675L,9c:61:21:1f:63:09,10,TKIP,WPA2PSK,\n\r29%,,52:3a:a0:03:1d:81,13,AES,WPA2PSK,\n\r13%,0xE68890E983BDE890A8E58D9AE696,6a:db:54:5a:5d:65,9,TKIP,WPA2PSK,\n\r7%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e7:0a:b6,1,NONE,OPEN,\n\r7%,10-1-906,b0:95:8e:ac:10:1d,1,TKIP,WPA2PSK,\n\r2%,360WiFi-3C73E7,c4:36:55:3c:73:e7,1,AES,WPA2PSK,\n\r10%,0xE4BC8AE79DBFE585B1E5889B,20:6b:e7:4d:fc:19,1,TKIP,WPA2PSK,\n\r10%,CTWS,88:25:93:b8:85:4d,3,NONE,OPEN,\n\r7%,0xE5889BE4B89A36E58CBAE5858DE8,06:69:6c:e9:dc:af,11,NONE,OPEN,\n\r0%,hwadee5,08:9b:4b:98:c3:56,1,NONE,OPEN,\n\r0%,Agile_VP,20:6b:e7:8d:bb:9b,1,AES,WPA2PSK,\n\r0%,hwadee1,08:9b:4b:98:c3:3e,1,NONE,OPEN,\n\r0%,js606,8c:f2:28:9d:e5:40,1,NONE,OPEN,\n\r0%,ChinaNet-MTLS,64:5d:92:9e:a7:11,3,TKIP,WPA2PSK,\n\r0%,3-2-2,c8:3a:35:15:d1:40,3,AES,WPA2PSK,\n\r0%,CMCC-RrrN,3c:fb:5c:5b:85:67,4,AES,WPA2PSK,\n\r0%,midea_ac_0313,fc:dd:55:1e:cf:f6,5,AES,WPA2PSK,\n\r0%,TP-LINK_2703,8c:a6:df:80:ae:67,6,AES,WPA2PSK,\n\r0%,TP-LINK_1A70,88:25:93:f6:1a:70,10,AES,WPA2PSK,\n\r0%,hwadee6,08:9b:4b:98:c2:86,11,NONE,OPEN,\n\r\r\n\r\n"

*/

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
    QRegExp atRegExp("AT\\+WSCAN.*\r\r\n\r\n");
    if(atRegExp.indexIn(receiveString)!=-1){
        qDebug()<<"成功截取";
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
            wifiList.append(new wifiData(wifiSSID+"---"+wifiRSSI,wifiRSSI.toInt()));
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


