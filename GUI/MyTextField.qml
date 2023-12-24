import QtQuick 2.3
import QtQuick.Controls

TextField {
    id: textField
   
    visible: true
    color: "#6f4a8e"
    horizontalAlignment: TextInput.AlignHCenter
    verticalAlignment: TextInput.AlignVCenter
    font.pointSize: 32
    placeholderTextColor: "#6f4a8e"


    background: Rectangle {
       color: "#ebebeb"
        radius: 20
    }
}
