import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs


Dialog{
    id:addMessage
    anchors.centerIn: parent
    height: 200
    width: 400
    property string placeholderText: "Input Name"
    property string inputText


    background: Rectangle {
        anchors.fill: parent
        color: "#ebebeb"
        radius: 20
    }


    MyTextField{
        id: txt
        anchors.centerIn: parent
        placeholderText: addMessage.placeholderText
        onTextChanged: inputText = txt.text
    }
    standardButtons: Dialog.Ok | Dialog.Cancel




}
