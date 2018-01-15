#include "applicationdata.h"

ApplicationData::ApplicationData()
{
    qDebug()<<"application is construct";


}

QList<QString> ApplicationData::getAllSerialPortName()
{
    QList<QString> serialPortNameList;
    foreach (QSerialPortInfo serialPortInfo, QSerialPortInfo::availablePorts()) {
        serialPortNameList.append(serialPortInfo.portName());
    }
    return serialPortNameList;
}
