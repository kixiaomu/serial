import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 900
    height: 640
    flags: Qt.FramelessWindowHint|Qt.Window
    Rectangle{
        id:test111
        anchors.fill: parent
        radius: 10
        HeaderBar{
            id:headerbar
            width: 900
            height: 48
            color: "#e6e6e6"
        }
        //中间内容
        Rectangle{
            id:swipeView_r
            width: 900
            height: 528
            anchors.top:headerbar.bottom
            radius: 10
            SwipeView{
                id:swipeView
                anchors.fill: parent
                currentIndex: footbar.currentIndex


                Page1{
                }

                Page{
                    Label{
                        anchors.centerIn: parent
                        text:"page.2"
                    }
                }
                Page{
                    Label{
                        anchors.centerIn: parent
                        text:"page.3"
                    }
                }
                Page{
                    Label{
                        anchors.centerIn: parent
                        text:"page.4"
                    }
                }
                onCurrentIndexChanged: footbar.currentIndex=currentIndex


            }

        }

        //底部导航按钮

        FootBar{
            id:footbar
            currentIndex: swipeView.currentIndex
            color: "#e6e6e6"
            anchors.top:swipeView_r.bottom
            width: 900
            height: 64
            radius: 10
            onCurrentIndexChanged: changeFootButtonState();

        }
    }



}



