import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    width: 900
    height: 528

    Button {
        id: button_wifi_debug
        objectName: "button_wifi_debug"
        x: 720
        y: 321
        width: 151
        height: 47
        text: qsTr("连接并进入调试")

    }

    Button {
        objectName: "button_wifi_test"
        id: button_wifi_test
        x: 720
        y: 388
        width: 151
        height: 40
        text: qsTr("WIFI扫描")
    }
     ScrollView {
         x: 70
         y: 73
         width: 609
         height: 355
         TextArea {
             id: page2_test_textArea

             text: receiveTextAreaString
             wrapMode: Text.WrapAnywhere
             background: Rectangle {
                 border.width: 1
                 border.color: "#58bace"
                 anchors.fill: parent
             }
             cursorPosition: text.length
         }
     }

}
