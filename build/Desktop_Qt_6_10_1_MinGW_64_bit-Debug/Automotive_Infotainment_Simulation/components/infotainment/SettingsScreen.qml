import QtQuick
import QtQuick.Layouts

// Settings screen
Item {
    id: root

    property color bgDeep:      "#0a0a0f"
    property color bgCard:      "#1a1a2e"
    property color accent:      "#00d4ff"
    property color accentAmber: "#ff8c00"
    property color textPrimary: "#e8e8f0"
    property color textDim:     "#7a7a9a"

    // Local settings state
    property double brightness: 80
    property double volume:     65
    property bool   darkTheme:  true
    property bool   useKmh:     true
    property bool   autoHdLights: false
    property double climateTemp: 22

    Rectangle {
        anchors.fill: parent
        color: root.bgDeep

        ColumnLayout {
            anchors { fill: parent; margins: 28 }
            spacing: 20

            Text {
                text: "⚙  SYSTEM SETTINGS"
                color: root.accent
                font.pixelSize: 14
                font.family: "Orbitron"
                font.letterSpacing: 2
            }

            // Settings cards grid
            GridLayout {
                Layout.fillWidth: true
                columns: 2
                columnSpacing: 16
                rowSpacing: 14

                // Card factory
                Repeater {
                    model: [
                        { title: "DISPLAY",     icon: "☀" },
                        { title: "AUDIO",       icon: "🔊" },
                        { title: "CLIMATE",     icon: "❄" },
                        { title: "VEHICLE",     icon: "🚗" },
                    ]
                    delegate: Rectangle {
                        Layout.fillWidth: true
                        width: 200; height: 130
                        radius: 12; color: root.bgCard
                        border.color: "#2a2a44"

                        Column {
                            anchors { fill: parent; margins: 14 }
                            spacing: 12

                            Row {
                                spacing: 8
                                Text { text: modelData.icon; font.pixelSize: 16 }
                                Text { text: modelData.title; color: root.textDim; font.pixelSize: 10; font.family: "Orbitron"; font.letterSpacing: 2; anchors.verticalCenter: parent.verticalCenter }
                            }

                            // Card-specific controls
                            Loader {
                                width: parent.width
                                sourceComponent: index === 0 ? displayCtrl :
                                                 index === 1 ? audioCtrl :
                                                 index === 2 ? climateCtrl : vehicleCtrl
                            }
                        }
                    }
                }

                // Display card
                Component {
                    id: displayCtrl
                    Column {
                        spacing: 8
                        Text { text: "Brightness  " + Math.round(root.brightness) + "%"; color: root.textPrimary; font.pixelSize: 12; font.family: "Rajdhani" }
                        Rectangle {
                            width: parent.width; height: 6; radius: 3; color: "#1e1e30"
                            Rectangle {
                                width: parent.width * (root.brightness / 100); height: parent.height; radius: 3; color: root.accent
                                Behavior on width { NumberAnimation { duration: 150 } }
                            }
                            MouseArea { anchors.fill: parent; onClicked: (m) => root.brightness = Math.round(m.x / parent.width * 100); cursorShape: Qt.PointingHandCursor }
                        }

                        Row {
                            spacing: 10
                            Text { text: "Dark Theme"; color: root.textPrimary; font.pixelSize: 11; font.family: "Rajdhani"; anchors.verticalCenter: parent.verticalCenter }
                            Rectangle {
                                width: 38; height: 20; radius: 10
                                color: root.darkTheme ? root.accent : "#333"
                                Behavior on color { ColorAnimation { duration: 250 } }
                                Rectangle {
                                    width: 16; height: 16; radius: 8
                                    anchors { verticalCenter: parent.verticalCenter; left: root.darkTheme ? undefined : parent.left; right: root.darkTheme ? parent.right : undefined; margins: 2 }
                                    color: "white"
                                    Behavior on anchors.leftMargin { NumberAnimation { duration: 200 } }
                                }
                                MouseArea { anchors.fill: parent; onClicked: root.darkTheme = !root.darkTheme; cursorShape: Qt.PointingHandCursor }
                            }
                        }
                    }
                }

                Component {
                    id: audioCtrl
                    Column {
                        spacing: 8
                        Text { text: "Volume  " + Math.round(root.volume) + "%"; color: root.textPrimary; font.pixelSize: 12; font.family: "Rajdhani" }
                        Rectangle {
                            width: parent.width; height: 6; radius: 3; color: "#1e1e30"
                            Rectangle {
                                width: parent.width * (root.volume / 100); height: parent.height; radius: 3; color: root.accentAmber
                                Behavior on width { NumberAnimation { duration: 150 } }
                            }
                            MouseArea { anchors.fill: parent; onClicked: (m) => root.volume = Math.round(m.x / parent.width * 100); cursorShape: Qt.PointingHandCursor }
                        }
                        Row {
                            spacing: 10
                            Text { text: "Equalizer"; color: root.textDim; font.pixelSize: 11; font.family: "Rajdhani"; anchors.verticalCenter: parent.verticalCenter }
                            Text { text: "FLAT"; color: root.accent; font.pixelSize: 10; font.family: "Orbitron"; anchors.verticalCenter: parent.verticalCenter }
                        }
                    }
                }

                Component {
                    id: climateCtrl
                    Column {
                        spacing: 8
                        Row {
                            spacing: 0
                            Text { text: Math.round(root.climateTemp) + "°C"; color: root.textPrimary; font.pixelSize: 22; font.family: "Orbitron"; font.bold: true }
                        }
                        Row {
                            spacing: 6
                            Repeater {
                                model: ["-2","-1","+1","+2"]
                                Rectangle {
                                    width: 32; height: 24; radius: 6; color: root.bgCard; border.color: root.accent; border.width: 1
                                    Text { anchors.centerIn: parent; text: modelData; color: root.accent; font.pixelSize: 11 }
                                    MouseArea { anchors.fill: parent; onClicked: root.climateTemp = Math.max(16, Math.min(30, root.climateTemp + parseFloat(modelData))); cursorShape: Qt.PointingHandCursor }
                                }
                            }
                        }
                    }
                }

                Component {
                    id: vehicleCtrl
                    Column {
                        spacing: 8
                        Row {
                            spacing: 10
                            Text { text: "Units"; color: root.textPrimary; font.pixelSize: 11; font.family: "Rajdhani"; anchors.verticalCenter: parent.verticalCenter }
                            Rectangle {
                                width: 60; height: 24; radius: 6; color: root.bgCard; border.color: root.accent; border.width: 1
                                Text { anchors.centerIn: parent; text: root.useKmh ? "km/h" : "mph"; color: root.accent; font.pixelSize: 11; font.family: "Orbitron" }
                                MouseArea { anchors.fill: parent; onClicked: root.useKmh = !root.useKmh; cursorShape: Qt.PointingHandCursor }
                            }
                        }
                        Row {
                            spacing: 10
                            Text { text: "Auto Lights"; color: root.textPrimary; font.pixelSize: 11; font.family: "Rajdhani"; anchors.verticalCenter: parent.verticalCenter }
                            Rectangle {
                                width: 38; height: 20; radius: 10
                                color: root.autoHdLights ? root.accent : "#333"
                                Behavior on color { ColorAnimation { duration: 250 } }
                                Rectangle {
                                    width: 16; height: 16; radius: 8
                                    anchors { verticalCenter: parent.verticalCenter; left: root.autoHdLights ? undefined : parent.left; right: root.autoHdLights ? parent.right : undefined; margins: 2 }
                                    color: "white"
                                }
                                MouseArea { anchors.fill: parent; onClicked: root.autoHdLights = !root.autoHdLights; cursorShape: Qt.PointingHandCursor }
                            }
                        }
                    }
                }
            }

            Item { Layout.fillHeight: true }
        }
    }
}
