import QtQuick

Rectangle {
    id : root
    width: 1080
    height: 720
    color: "#221f3b"
    signal currentProjectChanged(string name)
    signal goToProject(string name)
    signal goToTask(string name)
    signal addProject(string projectName)
    signal removeProject(string projectName)

    AddDialog{
        id: addProjectDialog;
        placeholderText: "input project name"
        onAccepted: root.addProject(inputText)

    }
    RemoveDialog{
        id: removeProjectDialog;
        onAccepted: root.removeProject(name)

    }



    MyList {
        id : projects
        width: 250
        height: 440
        anchors.verticalCenterOffset: -29
        anchors.horizontalCenterOffset: -234
        model: _projects
        onDoubleClickOnItem: goToProject(itemName)
        onAdd: addProjectDialog.open()
        onRemove: {
            removeProjectDialog.name = itemName
            removeProjectDialog.open()
        }
    }

Rectangle {
    id: rectangle
    x: 483
    y: 164
    width: 454
    height: 192
    color: "#ebebeb"
    radius: 20
    anchors.verticalCenterOffset: -153
    anchors.horizontalCenterOffset: 170
    anchors.centerIn: parent

    MyTextField {
        id: project
            x: 466
            y: 164
            width: 454
            height: 70
            text : projects.currentData
            anchors.verticalCenterOffset: -61
            anchors.horizontalCenterOffset: 0
            enabled: false
            anchors.centerIn: rectangle
            onDisplayTextChanged: currentProjectChanged(project.text)




    }



    Text {
        id: description
        x: 0
        y: 80
        width: 384
        height: 103
        font.pixelSize: 20
        anchors.verticalCenterOffset: 36
        anchors.horizontalCenterOffset: 0
        anchors.centerIn: parent
        color: "#6f4a8e"
        text: _description
    }
}



    MyList {
        id: tasks
        showButton: false
        x: -5
        y: -5
        width: 454
        height: 218
        anchors.horizontalCenterOffset: 170
        model: _tasks
        anchors.verticalCenterOffset: 82
        onDoubleClickOnItem: goToTask(itemName)
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
