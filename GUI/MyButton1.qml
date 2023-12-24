import QtQuick 2.3
import QtQuick.Controls



Button {

    id: root
    visible: true
    text: "button"
    clip: true
    enabled: true
    flat: true
    contentItem: Text {
        visible: true
        color: "#6f4a8e"
        text: root.text
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        clip: false
        font.pointSize: 32
    }

     background: Rectangle {
        
        radius: 25
        color: root.down ? "#050505" :  (root.hovered ? "#ebebeb" : "#050505")
    }
}
