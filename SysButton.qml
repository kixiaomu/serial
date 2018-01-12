import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Image {
    property string image_source_entered: ""
    property string image_source_exited: ""

    signal clicked
    id: sysbtn
    width: 16
    height: 16
    source: image_source_exited
    MouseArea {
        anchors.fill: parent
        onEntered: sysbtn.source = image_source_entered
        onExited: sysbtn.source = image_source_exited
        onClicked: sysbtn.clicked()
    }
}
