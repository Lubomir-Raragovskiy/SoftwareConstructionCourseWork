import QtQuick
import QtQuick.Controls

Rectangle {
    id : root
    width: 1080
    height: 720
    color: "#221f3b"

    property int taskId : _taskId

    signal saveTask(int id,
                    string name,
                    string deadline,
                    string description,
                    string assignee,
                    string project)



    SaveDialog{
        id: saveTaskDialog

        saveName: taskName.text
        onAccepted : saveTask(taskId,
                           taskName.text,
                           deadline.text,
                           decription.text,
                           user.currentText,
                           project.currentText)

    }

    Row {

        anchors.centerIn: parent
        spacing: 20
        anchors.verticalCenterOffset: -176
        anchors.horizontalCenterOffset: 1
        MyTextField {
            id: taskName
            width: 489
            height: 70
            text: _taskName
        }

        MyTextField {
            id: deadline
            width: 199
            height: 70
            text: _deadline
            font.pointSize: 20



        }

    }

    Rectangle {
        id: rectangle
        anchors.centerIn: parent
        width: 707
        height: 200
        color: "#EBEBEB"
        radius: 20
        anchors.verticalCenterOffset: 114
        anchors.horizontalCenterOffset: 1

        TextInput {
            anchors.centerIn: parent
            id: decription
            x: 50
            y: 27
            width: 608
            height: 147
            font.pixelSize: 22
            color: "#6f4a8e"
            text: _description
        }
    }

    MyComboBox {
        id: project
        headerText : _currentProject
        x: 187
        y: 258
        width: 330
        height: 63
        anchors.verticalCenterOffset: -70
        anchors.horizontalCenterOffset: -188
        anchors.centerIn: parent
        model : _project

    }

    MyComboBox {
        id: user
        headerText : _currentUser
        x: 564
        y: 258
        width: 330
        height: 63
        anchors.verticalCenterOffset: -70
        anchors.horizontalCenterOffset: 189
        anchors.centerIn: parent
        model : _user
    }

    MyButton1 {
        id: save
        anchors.centerIn: parent
        width: 707
        height: 70
        text: "Save changes"
        anchors.horizontalCenterOffset: 1
        anchors.verticalCenterOffset: 270
        onClicked: saveTaskDialog.open()
    }

    signal back()
    MyButton1 {
        id: backButton
        x: 0
        y: 8
        width: 185
        height: 54
        text: "Back"
        anchors.verticalCenter: parent.top - back.height
        anchors.horizontalCenter: parent.left - back.width
        onClicked: back()
    }
}
