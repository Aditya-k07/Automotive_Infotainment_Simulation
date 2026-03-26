import QtQuick
import QtQuick.Layouts

// Warning light icon grid
Item {
    id: root

    property color accentRed:   "#e74c3c"
    property color accentAmber: "#ff8c00"
    property color textDim:     "#7a7a9a"

    implicitWidth:  220
    implicitHeight: 48

    // warning model: [label, emoji, active, color]
    property var warnings: [
        { label: "ENG",  icon: "⚙",  active: vehicleCtrl.warningEngine,   col: accentRed   },
        { label: "BAT",  icon: "⚡",  active: vehicleCtrl.warningBattery,  col: accentAmber },
        { label: "OIL",  icon: "🛢",  active: vehicleCtrl.warningOil,      col: accentAmber },
        { label: "DOOR", icon: "🚗",  active: vehicleCtrl.warningDoor,     col: accentAmber },
        { label: "BELT", icon: "🔒", active: vehicleCtrl.warningSeatbelt, col: accentRed   },
    ]

    Row {
        anchors.centerIn: parent
        spacing: 8
        Repeater {
            model: root.warnings
            delegate: Column {
                spacing: 3
                Rectangle {
                    width: 36; height: 30; radius: 5
                    color: modelData.active ? modelData.col : "#1a1a2e"
                    border.color: modelData.active ? modelData.col : "#2a2a44"
                    border.width: 1
                    Behavior on color { ColorAnimation { duration: 250 } }

                    // Glow when active
                    layer.enabled: modelData.active
                    layer.effect: null

                    Text {
                        anchors.centerIn: parent
                        text: modelData.icon
                        font.pixelSize: 14
                        opacity: modelData.active ? 1.0 : 0.3
                        Behavior on opacity { NumberAnimation { duration: 250 } }
                    }

                    // Blink animation for active warnings
                    SequentialAnimation {
                        loops: Animation.Infinite
                        running: modelData.active
                        NumberAnimation { target: parent; property: "opacity"; to: 0.5; duration: 500 }
                        NumberAnimation { target: parent; property: "opacity"; to: 1.0; duration: 500 }
                    }
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: modelData.label
                    color: modelData.active ? modelData.col : root.textDim
                    font.pixelSize: 8
                    font.family: "Orbitron"
                }
            }
        }
    }
}
