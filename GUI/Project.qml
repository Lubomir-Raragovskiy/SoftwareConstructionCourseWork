import QtQuick 2.3


Rectangle {
    id : root
    width: 1080
    height: 720
    color: "#221f3b"
    property int projectId : _projectId

    signal addTask(string taskName, string projectName)
    signal completeTask(string taskName, string projectName)
    signal restoreTask(string taskName, string projectName)
    signal removeTask(string taskName, string projectName)

    signal saveProject(int projectId,
                       string projectName,
                       string description,
                       string version,
                       string projectManager)



    AddDialog{
        id: addTaskDialog;
        placeholderText: "input task name"
        onAccepted: root.addTask(addTaskDialog.inputText, projectName.text)

    }
    RemoveDialog{
        id: completeTaskDialog;
        message: "Are you sure you want to complete task \"" + completeTaskDialog.name + "\""

        onAccepted: root.completeTask(completeTaskDialog.name, projectName.text)

    }
    RemoveDialog{
        id: restoreTaskDialog;
        message: "Are you sure you want to restore task \"" + restoreTaskDialog.name + "\""

        onAccepted: root.restoreTask(restoreTaskDialog.name, projectName.text)

    }
    RemoveDialog{
        id: removeTaskDialog;

        onAccepted: root.removeTask(removeTaskDialog.name, projectName.text)

    }

    SaveDialog{
        id: saveProjectDialog;

        saveName: projectName.text

        onAccepted: root.saveProject(root.projectId, projectName.text, description.text,
                                     currentVersion.text, projectManager.displayText)

    }

        MyTextField {
            id: projectName
            x: 185
            y: 188
            width: 565
            height: 70
            text: _projectName
            anchors.verticalCenterOffset: -232
            anchors.horizontalCenterOffset: -107
            anchors.centerIn: parent
        }

        MyTextField {
            id: currentVersion
            x: 759
            y: 188
            width: 144
            height: 70
            text: _currentVersion
            anchors.verticalCenterOffset: -232
            anchors.horizontalCenterOffset: 263
            anchors.centerIn: parent
        }






        MyComboBox {
            id: projectManager
            x: 0
            y: 0
            width: 303
            height: 70
            model: _projectManager
            anchors.verticalCenterOffset: -119
            anchors.horizontalCenterOffset: -238
            anchors.centerIn: parent
            headerText: _currentPM
        }

        MyList {
            id: users
            showButton: false
            x: 0
            y: 105
            width: 302
            height: 269
            anchors.verticalCenterOffset: 78
            anchors.horizontalCenterOffset: -238
            model: _users
        }


    MyList {
        fontSize: 16
        id: activeTasks
        x: 1246
        y: 111
        width: 165
        height: 267
        anchors.centerIn: parent
        showButton: true
        removeText: "end"

        anchors.verticalCenterOffset: 79
        anchors.horizontalCenterOffset: 264
        model: _activeTasks
        onAdd: addTaskDialog.open()
        onRemove: {completeTaskDialog.name = itemName
            completeTaskDialog.open()}
    }

    MyList {
        fontSize: 16
        id: completedTask
        showButton: true
        addText: "restore"
        x: 1253
        y: 118
        width: 165
        height: 268
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: 64
        anchors.verticalCenterOffset: 78
        model: _completedTask

        onAdd: {restoreTaskDialog.name = itemName
            restoreTaskDialog.open()}
        onRemove: {removeTaskDialog.name = itemName
            removeTaskDialog.open()}
    }

    MyButton1 {
        id: save
        x: 150
        y: 578
        width: 303
        height: 70
        text: "Save changes"
        anchors.verticalCenterOffset: 261
        anchors.horizontalCenterOffset: -238
        onClicked: saveProjectDialog.open()
        anchors.centerIn: parent
    }

    Rectangle {
        id: rectangle
        width: 368
        height: 94
        color: "#ebebeb"
        radius: 20
        anchors.centerIn: parent
        TextInput {
            id : description
            x: 50
            y: 27
            width: 291
            height: 69
            color: "#6f4a8e"
            text: _description
            font.pixelSize: 18
            anchors.centerIn: parent
        }
        anchors.horizontalCenterOffset: 165
        anchors.verticalCenterOffset: -119
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
