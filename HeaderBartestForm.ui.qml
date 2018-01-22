import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle{
    width: 900
    height: 48
    Text {
        id: headerText
        height: parent.height
        color: "#58bace"
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
        }
        text: qsTr("YCF电子组上位机V1.0")
        font.bold: true
        font.pointSize: 16
        verticalAlignment: Text.AlignVCenter

    }

        SysButton{
            id:close
            anchors.right: parent.right
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/close_blue.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/close_gray.png"
            //anchors.verticalCenter: parent.verticalCenter

        }
        SysButton{
            id:roomIn
            anchors.right: close.left
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/roomIn_white.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/roomIn_gray.png"
            //anchors.verticalCenter: parent.verticalCenter

        }
        SysButton{
            anchors.right: roomIn.left
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/minimizing_gray.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/minimizing_gray.png"
            //anchors.verticalCenter: parent.verticalCenter

        }

}
