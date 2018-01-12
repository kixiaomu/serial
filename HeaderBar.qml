import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle{
    width: 900
    height: 48
    RowLayout{
        anchors.fill: parent
        width: 200
        height: 48
        SysButton{
            image_source_entered:"qrc:/png/sysbtn/sysbtn/close_blue.png"
            image_source_exited: "qrc:/png/sysbtn/sysbtn/close_gray.png"
            width: 16
            height: 16
            //anchors.verticalCenter: parent.verticalCenter
            onClicked: console.log("点击了关闭按钮");
        }
    }







}
