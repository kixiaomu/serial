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
#include <QRegExp>

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
    QString receiveString;

    QSerialPort m_serialPort;
    QSerialPortInfo m_serialPortInfo;
    int serial_combox_index=0;
    QList<QSerialPortInfo> serialPortInfoList;


public slots:
    void onScanClicked();
    void onListenClicked();
    void onWifitestClicked();
    void onWifiDebugClicked();
    void onClearClicked();
    void onActivated(int index);
    void onReadyRead();
    void onCurrentIndexChanged(int index);



};

#endif // APPLICATIONDATA_H
