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
    Rectangle {
        id: rectangle
        x: 720
        y: 81
        width: 151
        height: 227
        border.width: 1
        border.color: "#58bace"

        ListView {
            id: listView
            anchors.fill: parent
            anchors.margins: 10
            spacing: 4
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
            model: mymodel
            delegate: wifiListViewDelegate
            onCurrentIndexChanged: changeListViewState();


            function changeListViewState()
            {
                console.log("调用成功");



                /*
                for(var i=0;i<listView.children.length;i++)
                {
                    if(i!==currentIndex)
                    {
                        listView.children[i].state="unchecked";

                    }else
                    {
                        listView.children[i].state="checked";
                    }
                }*/
            }

        }
        Component {
            id: wifiListViewDelegate

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                id:wifiListViewDelegate_r


                height: 20
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


                MouseArea{
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onEntered: parent.color="#58bace"
                    onExited: parent.color="transparent"
                    onClicked: if(mouse.button === Qt.RightButton){

                               }else if(mouse.button===Qt.LeftButton){
                                   console.log("button_wifiConnect");
                                   parent.state="checked"
                                   listView.currentIndex=index;
                               }
                }
                Button {
                    id: button_wifiConnect
                    anchors{
                        right: parent.right
                        bottom: parent.bottom

                    }
                    width: 50
                    height: 0
                    text: qsTr("")
                    onClicked:console.log("inde:"+index)
                }
                states: [
                    State {
                        name: "checked"
                        when:wifiListViewDelegate_r.ListView.isCurrentItem
                        PropertyChanges {
                            target: button_wifiConnect
                            height:60


                        }
                    },
                    State{
                        name:"unchecked"
                        PropertyChanges {
                            target:wifiListViewDelegate_r
                            height:0


                        }
                    }
                ]

            }
        }



    }

}
