import QtQuick
import QtQuick.Layouts

// Full instrument cluster panel
Item {
    id: root

    // Colour tokens
    property color bgDeep:      "#0a0a0f"
    property color bgPanel:     "#111118"
    property color bgCard:      "#1a1a2e"
    property color accent:      "#00d4ff"
    property color accentAmber: "#ff8c00"
    property color accentRed:   "#e74c3c"
    property color textPrimary: "#e8e8f0"
    property color textDim:     "#7a7a9a"

    Rectangle {
        anchors.fill: parent
        color: root.bgDeep

        // Carbon-fibre subtle texture via repeating dots
        Canvas {
            anchors.fill: parent
            opacity: 0.03
            onPaint: {
                var ctx = getContext("2d");
                ctx.fillStyle = "#ffffff";
                for (var y = 0; y < height; y += 8) {
                    for (var x = 0; x < width; x += 8) {
                        ctx.beginPath();
                        ctx.arc(x, y, 0.8, 0, Math.PI * 2);
                        ctx.fill();
                    }
                }
            }
        }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 16
            spacing: 12

            // ── Top: Speedometer (centre) ──────────────────────────────
            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 230

                SpeedometerGauge {
                    anchors.centerIn: parent
                    width: 230; height: 230
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    bgCard:      root.bgCard
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
            }

            // ── Middle row: RPM + Gear indicator ──────────────────────
            RowLayout {
                Layout.fillWidth: true
                spacing: 12

                RPMGauge {
                    Layout.alignment: Qt.AlignVCenter
                    width: 170; height: 170
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    accentRed:   root.accentRed
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }

                // Gear + info column
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 10

                    // Gear indicator
                    Rectangle {
                        Layout.fillWidth: true
                        height: 70
                        radius: 10
                        color: root.bgCard
                        border.color: root.accent
                        border.width: 1
                        Column {
                            anchors.centerIn: parent
                            spacing: 2
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: "GEAR"
                                color: root.textDim
                                font.pixelSize: 9
                                font.family: "Orbitron"
                                font.letterSpacing: 2
                            }
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: vehicleCtrl.isDriving ? vehicleCtrl.gear : "P"
                                color: root.accent
                                font.pixelSize: 36
                                font.family: "Orbitron"
                                font.bold: true
                            }
                        }
                    }

                    // Drive toggle button
                    Rectangle {
                        Layout.fillWidth: true
                        height: 44
                        radius: 8
                        color: vehicleCtrl.isDriving ? root.accentAmber : root.accent
                        Behavior on color { ColorAnimation { duration: 300 } }

                        Text {
                            anchors.centerIn: parent
                            text: vehicleCtrl.isDriving ? "⏹  STOP" : "▶  DRIVE"
                            color: "#0a0a0f"
                            font.pixelSize: 14
                            font.family: "Orbitron"
                            font.bold: true
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: vehicleCtrl.toggleDriving()
                            cursorShape: Qt.PointingHandCursor
                        }
                        // hover glow
                        layer.enabled: true
                    }
                }
            }

            // ── Fuel + Temp gauges ────────────────────────────────────
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 8

                FuelGauge {
                    Layout.fillWidth: true
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    accentRed:   root.accentRed
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }

                TempGauge {
                    Layout.fillWidth: true
                    accent:      root.accent
                    accentAmber: root.accentAmber
                    accentRed:   root.accentRed
                    textPrimary: root.textPrimary
                    textDim:     root.textDim
                }
            }

            // ── Warning lights ────────────────────────────────────────
            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                WarningLights {
                    Layout.alignment: Qt.AlignHCenter
                    accentRed:   root.accentRed
                    accentAmber: root.accentAmber
                    textDim:     root.textDim
                }

                // Quick-toggle buttons for door/seatbelt
                Column {
                    spacing: 4
                    Rectangle {
                        width: 60; height: 22; radius: 5
                        color: vehicleCtrl.warningDoor ? root.accentAmber : root.bgCard
                        border.color: "#2a2a44"
                        Text { anchors.centerIn: parent; text: "DOOR"; font.pixelSize: 9; font.family: "Orbitron"; color: "#ccc" }
                        MouseArea { anchors.fill: parent; onClicked: vehicleCtrl.toggleDoor(); cursorShape: Qt.PointingHandCursor }
                    }
                    Rectangle {
                        width: 60; height: 22; radius: 5
                        color: vehicleCtrl.warningSeatbelt ? root.accentRed : root.bgCard
                        border.color: "#2a2a44"
                        Text { anchors.centerIn: parent; text: "BELT"; font.pixelSize: 9; font.family: "Orbitron"; color: "#ccc" }
                        MouseArea { anchors.fill: parent; onClicked: vehicleCtrl.toggleSeatbelt(); cursorShape: Qt.PointingHandCursor }
                    }
                }
            }

            Item { Layout.fillHeight: true }
        }
    }
}
