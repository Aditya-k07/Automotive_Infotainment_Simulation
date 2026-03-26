import QtQuick
import QtQuick.Layouts

// Infotainment panel with tab navigation
Item {
    id: root

    property color bgDeep:      "#0a0a0f"
    property color bgPanel:     "#111118"
    property color bgCard:      "#1a1a2e"
    property color accent:      "#00d4ff"
    property color accentAmber: "#ff8c00"
    property color accentRed:   "#e74c3c"
    property color textPrimary: "#e8e8f0"
    property color textDim:     "#7a7a9a"

    property int currentTab: 0  // 0=Media 1=Nav 2=Settings 3=Phone

    Rectangle {
        anchors.fill: parent
        color: root.bgPanel

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            // ── Tab bar ───────────────────────────────────────────────
            Rectangle {
                Layout.fillWidth: true
                height: 52
                color: root.bgDeep

                Row {
                    anchors.fill: parent
                    spacing: 0

                    Repeater {
                        model: [
                            { icon: "♫",  label: "MEDIA"  },
                            { icon: "🧭", label: "NAV"    },
                            { icon: "⚙",  label: "SETTINGS"},
                            { icon: "📱", label: "PHONE"  }
                        ]
                        delegate: Rectangle {
                            width:  parent.width / 4
                            height: parent.height
                            color:  root.currentTab === index ? root.bgPanel : "transparent"

                            // Active indicator line
                            Rectangle {
                                anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
                                height: 2
                                color: root.currentTab === index ? root.accent : "transparent"
                                Behavior on color { ColorAnimation { duration: 200 } }
                            }

                            Column {
                                anchors.centerIn: parent
                                spacing: 2
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: modelData.icon
                                    font.pixelSize: 16
                                    opacity: root.currentTab === index ? 1.0 : 0.4
                                    Behavior on opacity { NumberAnimation { duration: 200 } }
                                }
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: modelData.label
                                    color: root.currentTab === index ? root.accent : root.textDim
                                    font.pixelSize: 9
                                    font.family: "Orbitron"
                                    font.letterSpacing: 1
                                    Behavior on color { ColorAnimation { duration: 200 } }
                                }
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: root.currentTab = index
                                cursorShape: Qt.PointingHandCursor
                            }
                        }
                    }
                }
            }

            // ── Screen content ────────────────────────────────────────
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

                MediaPlayer {
                    anchors.fill: parent
                    visible: root.currentTab === 0
                    bgCard:      root.bgCard
                    bgDeep:      root.bgDeep
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
                NavigationScreen {
                    anchors.fill: parent
                    visible: root.currentTab === 1
                    bgCard:      root.bgCard
                    bgDeep:      root.bgDeep
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    accentRed:   root.accentRed
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
                SettingsScreen {
                    anchors.fill: parent
                    visible: root.currentTab === 2
                    bgCard:      root.bgCard
                    bgDeep:      root.bgDeep
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
                PhoneScreen {
                    anchors.fill: parent
                    visible: root.currentTab === 3
                    bgCard:      root.bgCard
                    bgDeep:      root.bgDeep
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    accentRed:   root.accentRed
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
            }
        }
    }
}
