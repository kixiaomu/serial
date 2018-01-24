import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


Rectangle{
     height: 60
     width: 151
    Image {
        anchors.left: parent.left
        id: wifi_image
        source: "qrc:/png/sysbtn/sysbtn/wifi_blue.png"
        width: 16
        height: 16
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        anchors.right: parent.right

        anchors.verticalCenter:parent.verticalCenter
        id: wifiSSIDText
        text:wifiSSID
        font.bold: true
        color: "#515151"
        width: 100
    }

    Button {
        id: button
        anchors{
            right: parent.right
            bottom: parent.bottom

        }
        width: 50
        height: 16
        text: qsTr("连接")
    }


}

