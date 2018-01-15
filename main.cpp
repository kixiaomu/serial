#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include "applicationdata.h"
/*
QML于C++交互之信号与槽(signal&slot )
https://www.cnblogs.com/findumars/p/6555687.html
*/

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    ApplicationData  appdata;
    QQmlApplicationEngine engine;
    QTimer *pTimer = new QTimer();

    pTimer->setInterval(1000);
    engine.rootContext()->setContextProperty("ptimer", pTimer);
    engine.rootContext()->setContextProperty("appdata",&appdata);



    //connect(pTimer, &QTimer::timeout, this, &ApplicationData::onTimeout);

    engine.rootContext()->setContextProperty("comboxModel",QVariant::fromValue(appdata.getAllSerialPortName()));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QObject* test = engine.findChild<QObject*>("test111");
    if(test)
    {
        qDebug()<<"查找成功";
    }


    pTimer->start();



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
