import QtQuick

Rectangle {
    id: root
    color: "#ebebeb"
    radius: 20
    property string currentData
    property string addText: "add"
    property string removeText: "remove"
    property variant model
    property bool showButton : true
    property int fontSize : 26
    signal doubleClickOnItem(string itemName)
    signal add(string itemName)
    signal remove(string itemName)
    anchors.centerIn: parent



    ListView {
        id: listView

        anchors.fill: parent


        model: root.model
        delegate: Item {
            id : it
            width: parent.width
            height: 60
            property variant myData: model

            Row {

                id: row
                spacing: 80

                Text {
                    id:txt
                    enabled: false
                    text: display
                    anchors.verticalCenter: parent.verticalCenter
                    width: it.width
                    color: "#6f4a8e"
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: root.fontSize
                }





            }
            MouseArea {
                                anchors.fill: parent
                                onClicked: {listView.currentIndex = index
                                    root.currentData = listView.currentItem.myData.display


                                }
                                onDoubleClicked: doubleClickOnItem(listView.currentItem.myData.display)

                            }
        }
        highlight: Rectangle {
                   color: "#8a6f4a8e"
                   radius: 20
                   height: it.height
                   width: it.width

                   anchors.verticalCenter: it.verticalCenter
                   transformOrigin: Item.TopLeft



               }
        focus: true
    }

    Column {
        width: parent.width

        anchors.horizontalCenter: parent.horizontalCenter
        y : parent.height
        MyButton1 {
            id: addButton
            width: parent.width
            height: 50
            visible: showButton
            text: addText
            onClicked: root.add(listView.currentItem.myData.display)
        }

        MyButton1 {
            id: removeButton
            width: parent.width
            visible: showButton
            height: 50
            text: removeText
            onClicked: root.remove(listView.currentItem.myData.display)
        }
        spacing: 10
    }

}
