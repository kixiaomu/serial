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
    foreach (QSerialPortInfo serialPortInfo, QSerialPortInfo::availablePorts()) {
        serialNameStringList.append(serialPortInfo.portName());
    }
    return serialNameStringList;
}

void ApplicationData::onScanClicked()
{
    qDebug()<<"64546";
}

