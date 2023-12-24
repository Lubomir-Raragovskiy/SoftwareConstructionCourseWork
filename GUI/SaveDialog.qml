import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs


Dialog{
    id:saveMessage
    anchors.centerIn: parent
    height: 200
    width: 400
    property string saveName


    background: Rectangle {
        anchors.fill: parent
        color: "#ebebeb"
        radius: 20
    }

    Text {
        id: name
        text: "Save changes in \"" + saveName + "\""
        color: "#6f4a8e"
        width: parent.width - 20;
        horizontalAlignment: Text.AlignHCenter
        anchors.centerIn : parent
        font.pointSize: 16

    }


    standardButtons: Dialog.Save | Dialog.Cancel

}
