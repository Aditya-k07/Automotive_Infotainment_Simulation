import QtQuick

// Horizontal segmented fuel bar
Item {
    id: root

    property double fuel:        vehicleCtrl.fuel
    property color  accent:      "#00d4ff"
    property color  accentAmber: "#ff8c00"
    property color  accentRed:   "#e74c3c"
    property color  textPrimary: "#e8e8f0"
    property color  textDim:     "#7a7a9a"

    implicitWidth:  180
    implicitHeight: 60

    property color barColor: fuel < 15 ? accentRed : fuel < 30 ? accentAmber : accent

    // Label
    Text {
        id: label
        anchors { left: parent.left; top: parent.top }
        text: "⛽  FUEL"
        color: root.textDim
        font.pixelSize: 10
        font.family: "Orbitron"
        font.letterSpacing: 2
    }

    Row {
        id: segments
        anchors { top: label.bottom; topMargin: 8; left: parent.left; right: parent.right }
        spacing: 3
        height: 14
        Repeater {
            model: 20
            Rectangle {
                width: (parent.width - 19 * 3) / 20
                height: parent.height
                radius: 2
                color: (index / 20.0) < (root.fuel / 100.0) ? root.barColor : "#1e1e30"
                Behavior on color { ColorAnimation { duration: 400 } }
            }
        }
    }

    Text {
        anchors { right: parent.right; top: parent.top }
        text: Math.round(root.fuel) + "%"
        color: root.barColor
        font.pixelSize: 13
        font.family: "Orbitron"
        Behavior on color { ColorAnimation { duration: 400 } }
    }

    // Low fuel warning blink
    SequentialAnimation {
        loops: Animation.Infinite
        running: root.fuel < 15
        NumberAnimation { target: segments; property: "opacity"; to: 0.3; duration: 600 }
        NumberAnimation { target: segments; property: "opacity"; to: 1.0; duration: 600 }
    }
}
