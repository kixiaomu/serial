#ifndef APPLICATIONDATA_H
#define APPLICATIONDATA_H

#include <QObject>
#include <QDateTime>
#include <QTimer>



class ApplicationData : public QObject
{
    Q_OBJECT
public:
    ApplicationData();
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
            return QDateTime::currentDateTime();
        }





};

#endif // APPLICATIONDATA_H
