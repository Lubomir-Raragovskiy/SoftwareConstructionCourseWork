import QtQuick 2.3
import QtQuick.Controls

Rectangle {
    id: main
    anchors.centerIn: parent
    width: 1080
    height: 720
    color: "#221f3b"
    signal logIn(string lg, string pw)
    signal signUp(string lg, string pw)



    Rectangle {
        anchors.centerIn: parent
        id: rectangle

        width: 678
        height: 85
        color: "#ebebeb"
        radius: 20
        anchors.verticalCenterOffset: -36
        anchors.horizontalCenterOffset: 0



        MyTextField {
            id: password
        x: 73
        y: 8
        width: 533
        height: 69
        visible: true
        color: "#6f4a8e"
        horizontalAlignment: Text.AlignHCenter
        placeholderText: qsTr("Password")
        layer.enabled: true
        font.pointSize: 32
        clip: false
        hoverEnabled: false
        placeholderTextColor: "#6f4a8e"
        echoMode: TextInput.Password
    }
        }



    Rectangle {
        anchors.centerIn: parent
        id: rectangle1
        x: 201
        y: 116

        width: 678
        height: 85
        color: "#ebebeb"
        radius: 20
        anchors.verticalCenterOffset: -165
        anchors.horizontalCenterOffset: 0

        MyTextField {
            id: login
            x: 102
            y: 8
            width: 475
            height: 69
            placeholderText: qsTr("Login")
        }
    }

    MyButton1 {
        anchors.centerIn: parent
        id: signUp
        x: 274
        y: 483
        width: 224
        height: 73
        text: qsTr("Sign up")
        anchors.verticalCenterOffset: 99
        anchors.horizontalCenterOffset: 155
         onClicked: main.signUp(login.text, password.text)
    }

   

    MyButton1 {
        objectName: "logIn"
        
        id: logIn
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -152
        anchors.verticalCenterOffset: 99
        height: 72
        text: "Log in"
        highlighted: false
        width: 215
        x: 582
        y: 483
        onClicked: main.logIn(login.text, password.text)
        
    }


}
