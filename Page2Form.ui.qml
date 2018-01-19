import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    width: 900
    height: 528

    Button {
        id: button
        x: 720
        y: 321
        width: 151
        height: 47
        text: qsTr("连接并进入调试")
    }

    Button {
        id: button1
        x: 720
        y: 388
        width: 151
        height: 40
        text: qsTr("测试")
    }

    TextArea {
        id: textArea
        x: 70
        y: 73
        width: 609
        height: 355
        text: qsTr("Text Area")
        wrapMode: Text.WrapAnywhere
        background: Rectangle {
            border.width: 1
            border.color: "#58bace"
            anchors.fill: parent
        }
    }

    Rectangle {
        id: rectangle
        x: 720
        y: 81
        width: 151
        height: 227
        color: "#ffffff"

        ListView {
            id: listView
            anchors.fill: parent
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
        }
    }
}
