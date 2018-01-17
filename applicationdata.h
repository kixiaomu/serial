#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>


class ApplicationData : public QObject
{
    Q_OBJECT
public:
    ApplicationData();
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
        return QDateTime::currentDateTime();
    }
    Q_INVOKABLE QStringList getAllSerialPortName();

    QQmlApplicationEngine* engine;
    QObject *receiveTextArea;

private:
    QSerialPort m_serialPort;
    QSerialPortInfo m_serialPortInfo;
    int serial_combox_index=0;
    QList<QSerialPortInfo> serialPortInfoList;


public slots:
    void onScanClicked();
    void onListenClicked();
    void onActivated(int index);
    void onReadyRead();


};

#endif // APPLICATIONDATA_H
