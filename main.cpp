#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include "applicationdata.h"
#include "wifidata.h"
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
    QStringList combox_list;
    combox_list<<"COM";
    engine.rootContext()->setContextProperty("comboxModel",QVariant::fromValue(combox_list));

    QList<QObject *> wifiList;
    wifiList.append(new wifiData("ycf01",11));
    wifiList.append(new wifiData("ycf02",22));
    wifiList.append(new wifiData("ycf03",33));

    engine.rootContext()->setContextProperty("mymodel",QVariant::fromValue(wifiList));


    engine.rootContext()->setContextProperty("receiveTextAreaString","123456");


    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    appdata.engine=&engine;
    QObject* button_scan = engine.rootObjects()[0]->findChild<QObject*>("button_scan");
    if(button_scan)
    {
        QObject::connect(button_scan,SIGNAL(clicked()),&appdata,SLOT(onScanClicked()));
        qDebug()<<"button_scan";
    }

    QObject* button_listen = engine.rootObjects()[0]->findChild<QObject*>("button_listen");
    if(button_listen)
    {
        QObject::connect(button_listen,SIGNAL(clicked()),&appdata,SLOT(onListenClicked()));
        qDebug()<<"button_listen";
    }




    QObject* serialport_comboBox = engine.rootObjects()[0]->findChild<QObject*>("serialport_comboBox");
    if(serialport_comboBox)
    {
        QObject::connect(serialport_comboBox,SIGNAL(activated(int)),&appdata,SLOT(onActivated(int)));
        qDebug()<<"serialport_comboBox";
    }

    QObject* button_wifi_test = engine.rootObjects()[0]->findChild<QObject*>("button_wifi_test");
    if(button_wifi_test)
    {
        QObject::connect(button_wifi_test,SIGNAL(clicked()),&appdata,SLOT(onWifitestClicked()));

    }

    QObject* button_wifi_debug = engine.rootObjects()[0]->findChild<QObject*>("button_wifi_debug");
    if(button_wifi_test)
    {
        QObject::connect(button_wifi_debug,SIGNAL(clicked()),&appdata,SLOT(onWifiDebugClicked()));

    }
    QObject* button_clear = engine.rootObjects()[0]->findChild<QObject*>("button_clear");
    if(button_clear)
    {
        QObject::connect(button_clear,SIGNAL(clicked()),&appdata,SLOT(onClearClicked()));

    }
    QObject* swipeView_r = engine.rootObjects()[0]->findChild<QObject*>("swipeView_r");
    if(swipeView_r)
    {
        QObject::connect(swipeView_r,SIGNAL(onCurrentIndexChanged(int)),&appdata,SLOT(onCurrentIndexChanged(int)));

    }



    pTimer->start();



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
