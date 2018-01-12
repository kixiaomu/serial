import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle {
    id:footbutton
    property string image_source: ""
    property string button_name: ""
    property int index: 0
    property color back_color: "transparent"
    signal clicked


    width: 128
    height: 48
    radius: 8
    color: back_color

    Image {
        id: image_footbutton
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 8
        width: 32
        height: 32
        source: image_source
    }
    Text {
        color: "#5d5d5d"
        anchors.left: image_footbutton.right
        anchors.verticalCenter: parent.verticalCenter

        text: qsTr(button_name)
        font.family: "Arial"
        font.pointSize: 16
        font.bold: true
    }
    MouseArea{
        anchors.fill: parent
        onClicked:{
            footbutton.state="checked";
            footbutton.clicked();
        }
    }
    states:[
        State {
            name: "checked"
            PropertyChanges {
                target: footbutton
                color:"black"

            }
        },
        State {
            name: "unchecked"
            PropertyChanges {
                target: footbutton
                color:"transparent"

            }
        }
    ]

}
