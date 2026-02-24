import QtQuick
import QtQuick.Layouts

// Bluetooth / Phone screen
Item {
    id: root

    property color bgDeep:      "#0a0a0f"
    property color bgCard:      "#1a1a2e"
    property color accent:      "#00d4ff"
    property color accentAmber: "#ff8c00"
    property color accentRed:   "#e74c3c"
    property color textPrimary: "#e8e8f0"
    property color textDim:     "#7a7a9a"

    Rectangle {
        anchors.fill: parent
        color: root.bgDeep

        ColumnLayout {
            anchors { fill: parent; margins: 24 }
            spacing: 16

            // Header
            Row {
                spacing: 12
                Text {
                    text: "📱  BLUETOOTH & PHONE"
                    color: root.accent
                    font.pixelSize: 14
                    font.family: "Orbitron"
                    font.letterSpacing: 2
                    anchors.verticalCenter: parent.verticalCenter
                }
                // Signal strength metres
                Row {
                    visible: btCtrl.isConnected
                    spacing: 2
                    anchors.verticalCenter: parent.verticalCenter
                    Repeater {
                        model: 4
                        Rectangle {
                            width: 4; height: 6 + index * 4; radius: 1
                            anchors.bottom: parent.bottom
                            color: btCtrl.signalStrength > index * 25 ? root.accent : "#333350"
                            Behavior on color { ColorAnimation { duration: 400 } }
                        }
                    }
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        text: btCtrl.signalStrength + "%"
                        color: root.textDim
                        font.pixelSize: 10
                        font.family: "Rajdhani"
                        leftPadding: 4
                    }
                }
            }

            // Connection status
            Rectangle {
                Layout.fillWidth: true
                height: 54
                radius: 10
                color: root.bgCard
                border.color: btCtrl.isConnected ? root.accent : "#2a2a44"
                border.width: btCtrl.isConnected ? 2 : 1
                Behavior on border.color { ColorAnimation { duration: 300 } }

                RowLayout {
                    anchors { fill: parent; leftMargin: 16; rightMargin: 16 }
                    spacing: 12

                    // BT icon pulsing
                    Rectangle {
                        width: 32; height: 32; radius: 8
                        color: btCtrl.isConnected ? root.accent : "#1e1e30"
                        Behavior on color { ColorAnimation { duration: 300 } }
                        Text { anchors.centerIn: parent; text: "⬡"; font.pixelSize: 16; color: btCtrl.isConnected ? "#0a0a0f" : root.textDim }

                        SequentialAnimation {
                            loops: Animation.Infinite
                            running: btCtrl.isConnected
                            NumberAnimation { target: parent; property: "opacity"; to: 0.6; duration: 800 }
                            NumberAnimation { target: parent; property: "opacity"; to: 1.0; duration: 800 }
                        }
                    }

                    Column {
                        Layout.fillWidth: true
                        spacing: 2
                        Text {
                            text: btCtrl.isConnected ? btCtrl.deviceName : "Not Connected"
                            color: btCtrl.isConnected ? root.textPrimary : root.textDim
                            font.pixelSize: 14
                            font.family: "Rajdhani"
                        }
                        Text {
                            text: btCtrl.isConnected ? "Connected · Audio" : "Searching for devices…"
                            color: btCtrl.isConnected ? root.accent : root.textDim
                            font.pixelSize: 11
                            font.family: "Rajdhani"
                        }
                    }

                    Rectangle {
                        width: 90; height: 32; radius: 8
                        color: btCtrl.isConnected ? root.accentRed : root.accent

                        Text {
                            anchors.centerIn: parent
                            text: btCtrl.isConnected ? "Disconnect" : "Scan"
                            color: "#0a0a0f"; font.pixelSize: 11; font.family: "Orbitron"
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: btCtrl.isConnected ? btCtrl.disconnectDevice() : {}
                            cursorShape: Qt.PointingHandCursor
                        }
                    }
                }
            }

            // Device list
            Text {
                text: "AVAILABLE DEVICES"
                color: root.textDim
                font.pixelSize: 9
                font.family: "Orbitron"
                font.letterSpacing: 2
            }

            Column {
                Layout.fillWidth: true
                spacing: 6
                Repeater {
                    model: btCtrl.availableDevices
                    delegate: Rectangle {
                        width: parent.width; height: 50; radius: 10
                        color: btCtrl.isConnected && btCtrl.deviceName === modelData ? "#0a2030" : root.bgCard
                        border.color: btCtrl.isConnected && btCtrl.deviceName === modelData ? root.accent : "#2a2a44"
                        border.width: 1

                        RowLayout {
                            anchors { fill: parent; leftMargin: 14; rightMargin: 14 }
                            spacing: 12

                            Text { text: "⬡"; font.pixelSize: 18; color: btCtrl.isConnected && btCtrl.deviceName === modelData ? root.accent : root.textDim }
                            Column {
                                Layout.fillWidth: true
                                spacing: 2
                                Text { text: modelData; color: root.textPrimary; font.pixelSize: 13; font.family: "Rajdhani" }
                                Text { text: "Bluetooth 5.2 · LE Audio"; color: root.textDim; font.pixelSize: 10; font.family: "Rajdhani" }
                            }

                            Rectangle {
                                width: 72; height: 28; radius: 6
                                color: btCtrl.isConnected && btCtrl.deviceName === modelData ? root.accentRed : root.accent
                                visible: !btCtrl.isConnected || btCtrl.deviceName === modelData
                                Text {
                                    anchors.centerIn: parent
                                    text: btCtrl.isConnected && btCtrl.deviceName === modelData ? "Disconnect" : "Connect"
                                    color: "#0a0a0f"; font.pixelSize: 10; font.family: "Orbitron"
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: btCtrl.isConnected && btCtrl.deviceName === modelData
                                               ? btCtrl.disconnectDevice()
                                               : btCtrl.connectDevice(modelData)
                                    cursorShape: Qt.PointingHandCursor
                                }
                            }
                        }
                    }
                }
            }

            Item { Layout.fillHeight: true }
        }

        // ── Incoming call overlay ───────────────────────────────────
        Rectangle {
            anchors.fill: parent
            color: "rgba(0,0,0,0.85)"
            visible: btCtrl.hasIncoming || btCtrl.isInCall
            radius: 0

            Behavior on opacity { NumberAnimation { duration: 300 } }

            Rectangle {
                anchors.centerIn: parent
                width: 320; height: 260; radius: 20
                color: "#0f0f1f"
                border.color: btCtrl.isInCall ? root.accent : root.accentAmber
                border.width: 2

                SequentialAnimation {
                    loops: Animation.Infinite
                    running: btCtrl.hasIncoming
                    NumberAnimation { target: parent.border; property: "width"; to: 3; duration: 400 }
                    NumberAnimation { target: parent.border; property: "width"; to: 2; duration: 400 }
                }

                Column {
                    anchors.centerIn: parent
                    spacing: 16

                    // Avatar circle
                    Rectangle {
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 72; height: 72; radius: 36
                        color: btCtrl.isInCall ? root.accent : root.accentAmber
                        Text { anchors.centerIn: parent; text: "👤"; font.pixelSize: 32 }
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: btCtrl.isInCall ? "On Call" : "Incoming Call"
                        color: root.textDim
                        font.pixelSize: 12; font.family: "Orbitron"
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: btCtrl.callerName || btCtrl.deviceName
                        color: root.textPrimary
                        font.pixelSize: 20; font.family: "Orbitron"; font.bold: true
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        visible: btCtrl.isInCall
                        text: btCtrl.callDuration
                        color: root.accent
                        font.pixelSize: 22; font.family: "Orbitron"
                    }

                    Row {
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: 16

                        // Reject / End
                        Rectangle {
                            width: 56; height: 56; radius: 28
                            color: root.accentRed
                            Text { anchors.centerIn: parent; text: "📵"; font.pixelSize: 22 }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: btCtrl.isInCall ? btCtrl.endCall() : btCtrl.rejectCall()
                                cursorShape: Qt.PointingHandCursor
                            }
                        }

                        // Answer (only when incoming)
                        Rectangle {
                            width: 56; height: 56; radius: 28
                            color: "#1a8a1a"
                            visible: btCtrl.hasIncoming && !btCtrl.isInCall
                            Text { anchors.centerIn: parent; text: "📞"; font.pixelSize: 22 }
                            MouseArea { anchors.fill: parent; onClicked: btCtrl.answerCall(); cursorShape: Qt.PointingHandCursor }
                        }
                    }
                }
            }
        }
    }
}
