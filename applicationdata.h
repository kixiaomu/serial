#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort>
#include <QSerialPortInfo>



class ApplicationData : public QObject
{
    Q_OBJECT
public:
    ApplicationData();
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
        return QDateTime::currentDateTime();
    }
    Q_INVOKABLE QStringList getAllSerialPortName();
private:
    QSerialPort m_serialPort;
    QSerialPortInfo m_serialPortInfo;
public slots:
    void onScanClicked();



};

#endif // APPLICATIONDATA_H
