import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    id: m_page1
    width: 900
    height: 528
    signal scanClicked
    GroupBox {
        id: groupBox
        x: 38
        y: 40
        width: 584
        height: 226
        title: qsTr("接收")

        ScrollView {
            anchors.fill: parent

            TextArea {
                objectName: "receiveTextArea"
                id: receiveTextArea
                //width: parent.width
                text: receiveTextAreaString
                wrapMode: Text.WrapAnywhere
                onTextChanged: console.log("onTextChanged")
                cursorPosition: text.length
            }
        }
    }

    GroupBox {
        id: groupBox1
        x: 669
        y: 40
        width: 200
        height: 452
        title: qsTr("配置")

        Label {
            id: label
            x: 0
            y: 28
            width: 60
            height: 40

            text: qsTr("端口：")
            fontSizeMode: Text.FixedSize
            font.pointSize: 20
        }

        ComboBox {
            id: serialport_comboBox
            objectName: "serialport_comboBox"
            x: 75
            y: 20
            width: 90
            height: 40
            model:comboxModel
            onCurrentIndexChanged: console.log("当前值:"+currentIndex)
        }


        Button {
            id: button_scan
            objectName: "button_scan"
            x: 0
            y: 296
            width: 69
            height: 40
            text: qsTr("开始扫描")
        }
        Button {
            id: button_listen
            objectName: "button_listen"
            x: 107
            y: 296
            width: 69
            height: 40
            text: qsTr("开始监听")

        }

        Button {
            id: button_send
            objectName: "button_send"
            x: 0
            y: 361
            width: 69
            height: 40
            text: qsTr("发送")

        }

        Button {
            id: button_clear
            objectName: "button_clear"
            x: 107
            y: 361
            width: 69
            height: 40
            text: qsTr("清除")

        }



    }

    GroupBox {
        id: groupBox2
        x: 38
        y: 311
        width: 584
        height: 139
        title: qsTr("发送")
        ScrollView {
            anchors.fill: parent
            TextArea {
                id: textArea1
                //anchors.fill: parent
                text: qsTr("Text Area")
            }
        }
    }
    Component.onCompleted: {
        console.log(appdata.getAllSerialPortName());

    }
}
