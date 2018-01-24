import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle{
    width: 900
    height: 48

        SysButton{
            id:close
            anchors.right: parent.right
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/close_blue.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/close_gray.png"
            //anchors.verticalCenter: parent.verticalCenter
            onClicked: console.log("点击了关闭按钮");
        }
        SysButton{
            id:roomIn
            anchors.right: close.left
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/roomIn_white.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/roomIn_gray.png"
            //anchors.verticalCenter: parent.verticalCenter
            onClicked: console.log("点击了缩放按钮");
        }
        SysButton{
            anchors.right: roomIn.left
            anchors.rightMargin: 16
            image_source_entered:"qrc:/png/sysbtn/sysbtn/minimizing_gray.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/minimizing_gray.png"
            //anchors.verticalCenter: parent.verticalCenter
            onClicked: console.log("点击了最小化按钮");
        }

}
