import QtQuick
import QtQuick.Controls

ComboBox {
    id: comboBox
    x: 118
    y: 61
    width: 112
    height: 40
    property variant headerText
    textRole: "display"
    delegate: ItemDelegate {
        id: it
        width: parent.width
        height: 50

            contentItem : Text {
                id : txt
                text: model.display
                anchors.verticalCenter: parent.verticalCenter
                color: "#6f4a8e"
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter

            }
            highlighted: comboBox.highlightedIndex === index

            background: Rectangle {
                       color: it.highlighted ? "#8a6f4a8e" : "transparent"
                   }
            onClicked: {
            comboBox.currentIndex = index
            headerText = currentText
            }



    }

    contentItem : Text {
        id : curText
        rightPadding: comboBox.indicator.width + comboBox.spacing
        anchors.fill: parent
        color: "#6f4a8e"
        text: headerText
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 32
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter

    }


    background: Rectangle {
        implicitWidth: 120
        implicitHeight: 50
        color: "#EBEBEB"
        radius: 20
    }


}
