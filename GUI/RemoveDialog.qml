import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs


Dialog{
    id:removeMessage
    anchors.centerIn: parent
    height: 200
    width: 400
    property string name
    property string message : "Are you sure you want to remove \"" + name + "\""


    background: Rectangle {
        anchors.fill: parent
        color: "#ebebeb"
        radius: 20
    }

    Text {
        id: txt
        text: message
        color: "#6f4a8e"
        width: parent.width - 20;
        horizontalAlignment: Text.AlignHCenter
        anchors.centerIn : parent
        font.pointSize: 16

    }


    standardButtons: Dialog.Ok | Dialog.Cancel

}
