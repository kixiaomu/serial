import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


Rectangle {
    id:m_footbar

    property int currentIndex: 0
    function changeFootButtonState()
    {
        for(var i=0;i<m_footbar_r.children.length;i++)
        {
            if(i!==currentIndex)
            {
                m_footbar_r.children[i].state="unchecked";
            }else
            {
                m_footbar_r.children[i].state="checked";
            }
        }

    }
    RowLayout {
        id:m_footbar_r
        spacing: 64 + 32
        anchors.centerIn: parent

        FootButton{
            index:0
            image_source: "qrc:/png/sysbtn/sysbtn/serial_white.png"
            button_name: "串口调试"
            onClicked:m_footbar.currentIndex=0

        }
        FootButton{
            index:1
            image_source: "qrc:/png/sysbtn/sysbtn/serial_blue.png"
            button_name: "模拟仿真"
            onClicked: m_footbar.currentIndex=1

        }
        FootButton{
            index:2
            image_source: "qrc:/png/sysbtn/sysbtn/serial_blue.png"
            button_name: "位置预留"
            onClicked: m_footbar.currentIndex=2

        }
        FootButton{
            index:3
            image_source: "qrc:/png/sysbtn/sysbtn/tool_blue.png"
            button_name: "工具设置"
            onClicked: m_footbar.currentIndex=3

        }


    }

}

