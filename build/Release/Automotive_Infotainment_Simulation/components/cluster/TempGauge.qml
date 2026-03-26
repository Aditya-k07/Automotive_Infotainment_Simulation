import QtQuick

// Horizontal temp bar with hot/cold coloring
Item {
    id: root

    property double temp:        vehicleCtrl.engineTemp
    property color  accent:      "#00d4ff"
    property color  accentAmber: "#ff8c00"
    property color  accentRed:   "#e74c3c"
    property color  textPrimary: "#e8e8f0"
    property color  textDim:     "#7a7a9a"

    implicitWidth:  180
    implicitHeight: 60

    property color barColor: temp > 110 ? accentRed : temp > 95 ? accentAmber : accent

    Text {
        id: label
        anchors { left: parent.left; top: parent.top }
        text: "🌡  TEMP"
        color: root.textDim
        font.pixelSize: 10
        font.family: "Orbitron"
        font.letterSpacing: 2
    }

    Rectangle {
        id: trackBg
        anchors { top: label.bottom; topMargin: 8; left: parent.left; right: parent.right }
        height: 14
        radius: 7
        color: "#1e1e30"

        Rectangle {
            width: parent.width * Math.max(0, Math.min(root.temp / 130.0, 1.0))
            height: parent.height
            radius: 7
            color: root.barColor
            Behavior on width { NumberAnimation { duration: 600; easing.type: Easing.OutCubic } }
            Behavior on color { ColorAnimation { duration: 400 } }

            // Glow
            layer.enabled: true
            layer.effect: null
        }
    }

    Text {
        anchors { right: parent.right; top: parent.top }
        text: Math.round(root.temp) + "°C"
        color: root.barColor
        font.pixelSize: 13
        font.family: "Orbitron"
        Behavior on color { ColorAnimation { duration: 400 } }
    }
}
