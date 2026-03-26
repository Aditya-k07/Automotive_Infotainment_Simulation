import QtQuick
import QtQuick.Layouts

Item {
    id: root

    // ── Global colour tokens ───────────────────────────────────────────────
    readonly property color bgDeep:      "#0a0a0f"
    readonly property color bgPanel:     "#111118"
    readonly property color bgCard:      "#1a1a2e"
    readonly property color accent:      "#00d4ff"
    readonly property color accentAmber: "#ff8c00"
    readonly property color accentRed:   "#e74c3c"
    readonly property color textPrimary: "#e8e8f0"
    readonly property color textDim:     "#7a7a9a"

    // ── Top status bar ─────────────────────────────────────────────────────
    Rectangle {
        id: statusBar
        anchors { top: parent.top; left: parent.left; right: parent.right }
        height: 36
        color: "#0d0d1a"

        Row {
            anchors { left: parent.left; leftMargin: 16; verticalCenter: parent.verticalCenter }
            spacing: 20

            Text {
                text: Qt.formatDateTime(new Date(), "hh:mm")
                color: root.textDim
                font.pixelSize: 13
                font.family: "Rajdhani"
                Timer { interval: 30000; running: true; repeat: true; onTriggered: parent.text = Qt.formatDateTime(new Date(), "hh:mm") }
            }
            Text {
                text: Qt.formatDate(new Date(), "ddd, MMM d")
                color: root.textDim
                font.pixelSize: 13
                font.family: "Rajdhani"
            }
        }

        Row {
            anchors { right: parent.right; rightMargin: 16; verticalCenter: parent.verticalCenter }
            spacing: 14

            // BT icon
            Rectangle {
                width: 22; height: 22; radius: 3
                color: btCtrl.isConnected ? root.accent : "#333350"
                Text { anchors.centerIn: parent; text: "⬡"; color: "white"; font.pixelSize: 11 }
            }
            // Signal bars (mock)
            Row {
                spacing: 2; anchors.verticalCenter: parent.verticalCenter
                Repeater {
                    model: 4
                    Rectangle {
                        width: 4; height: 6 + index * 4; radius: 1
                        anchors.bottom: parent.bottom
                        color: btCtrl.isConnected && btCtrl.signalStrength > index * 25 ? root.accent : "#333350"
                    }
                }
            }
            Text {
                text: "EV"
                color: root.accentAmber
                font.pixelSize: 11
                font.bold: true
                font.family: "Orbitron"
            }
        }

        // centre title
        Text {
            anchors.centerIn: parent
            text: "QUANTUM AUTO HMI"
            color: root.accent
            font.pixelSize: 12
            font.family: "Orbitron"
            font.letterSpacing: 3
            opacity: 0.7
        }
    }

    // ── Main content row ──────────────────────────────────────────────────
    RowLayout {
        anchors {
            top: statusBar.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        spacing: 0

        // Left 42% — Instrument Cluster
        InstrumentCluster {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.42
            bgDeep:      root.bgDeep
            bgPanel:     root.bgPanel
            bgCard:      root.bgCard
            accent:      root.accent
            accentAmber: root.accentAmber
            accentRed:   root.accentRed
            textPrimary: root.textPrimary
            textDim:     root.textDim
        }

        // Vertical divider
        Rectangle {
            Layout.fillHeight: true
            width: 1
            color: root.accent
            opacity: 0.15
        }

        // Right 58% — Infotainment
        InfotainmentPanel {
            Layout.fillHeight: true
            Layout.fillWidth: true
            bgDeep:      root.bgDeep
            bgPanel:     root.bgPanel
            bgCard:      root.bgCard
            accent:      root.accent
            accentAmber: root.accentAmber
            accentRed:   root.accentRed
            textPrimary: root.textPrimary
            textDim:     root.textDim
        }
    }
}
