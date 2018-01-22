#ifndef WIFIDATA_H
#define WIFIDATA_H
#include <QObject>

class wifiData: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString wifiSSID READ wifiSSID WRITE setWifiSSID NOTIFY wifiSSIDChanged)
    Q_PROPERTY(int wifiRSSI READ wifiRSSI WRITE setWifiRSSI NOTIFY wifiRSSIChanged)

public:
    wifiData();
    wifiData(QString wifiSSID,int wifiRSSI, QObject *parent=0);


    QString wifiSSID();
    void setWifiSSID(QString wifiSSID_v);


    int wifiRSSI();
    void setWifiRSSI(int wifiRSSI_v);

signals:
    void wifiSSIDChanged();
    void wifiRSSIChanged();
private:
    QString m_wifiSSID;
    int m_wifiRSSI;

};

#endif // WIFIDATA_H
