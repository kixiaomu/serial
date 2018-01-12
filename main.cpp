#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include "applicationdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    ApplicationData  appdata;
    QQmlApplicationEngine engine;
    QTimer *pTimer = new QTimer();

    pTimer->setInterval(1000);
    engine.rootContext()->setContextProperty("ptimer", pTimer);
    engine.rootContext()->setContextProperty("datetime",&appdata);



    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    //connect(pTimer, &QTimer::timeout, this, &ApplicationData::onTimeout);
    pTimer->start();



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
