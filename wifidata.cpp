#include "wifidata.h"

wifiData::wifiData()
{

}

wifiData::wifiData(QString wifiSSID, int wifiRSSI, QObject *parent):QObject(parent),m_wifiSSID(wifiSSID),m_wifiRSSI(wifiRSSI)
{

}

QString wifiData::wifiSSID()
{
    return m_wifiSSID;
}

void wifiData::setWifiSSID(QString wifiSSID_v)
{
    m_wifiSSID=wifiSSID_v;
    emit wifiSSIDChanged();
}

int wifiData::wifiRSSI()
{
    return wifiRSSI();
    emit wifiRSSIChanged();
}

void wifiData::setWifiRSSI(int wifiRSSI_v)
{
    m_wifiRSSI=wifiRSSI_v;
}

