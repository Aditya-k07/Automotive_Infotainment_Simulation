import QtQuick
import QtQuick.Layouts

// Media player screen
Item {
    id: root

    property color bgDeep:      "#0a0a0f"
    property color bgCard:      "#1a1a2e"
    property color accent:      "#00d4ff"
    property color accentAmber: "#ff8c00"
    property color textPrimary: "#e8e8f0"
    property color textDim:     "#7a7a9a"

    Rectangle {
        anchors.fill: parent
        color: root.bgDeep

        RowLayout {
            anchors { fill: parent; margins: 24 }
            spacing: 28

            // ── Left: Album art + EQ visualiser ──────────────────────
            Column {
                spacing: 16
                Layout.alignment: Qt.AlignVCenter

                // Album art
                Rectangle {
                    width: 180; height: 180
                    radius: 16
                    color: root.bgCard
                    border.color: root.accent
                    border.width: mediaCtrl.isPlaying ? 2 : 1
                    Behavior on border.width { NumberAnimation { duration: 300 } }

                    // Abstract album art generated with gradients
                    Canvas {
                        anchors.fill: parent
                        anchors.margins: 0
                        property int trackIdx: mediaCtrl.trackIndex
                        onTrackIdxChanged: requestPaint()
                        onPaint: {
                            var ctx = getContext("2d");
                            ctx.reset();
                            var colors = [
                                ["#00d4ff","#7b2ff7"],
                                ["#ff8c00","#ff2d55"],
                                ["#00ff88","#00d4ff"],
                                ["#ff2d55","#7b2ff7"],
                                ["#ffcc00","#ff8c00"],
                            ];
                            var idx = trackIdx % 5;
                            var grd = ctx.createRadialGradient(90,90,10,90,90,100);
                            grd.addColorStop(0, colors[idx][0]);
                            grd.addColorStop(1, colors[idx][1]);
                            ctx.fillStyle = grd;
                            ctx.beginPath();
                            ctx.roundRect(0, 0, width, height, 16);
                            ctx.fill();
                            // Centre circle
                            ctx.beginPath();
                            ctx.arc(90, 90, 28, 0, Math.PI*2);
                            ctx.fillStyle = "rgba(0,0,0,0.4)";
                            ctx.fill();
                            ctx.beginPath();
                            ctx.arc(90,90,10,0,Math.PI*2);
                            ctx.fillStyle = "rgba(0,0,0,0.7)";
                            ctx.fill();
                        }
                    }

                    // Spinning vinyl when playing
                    RotationAnimation {
                        target: albumCanvas
                        running: mediaCtrl.isPlaying
                        from: 0; to: 360
                        duration: 8000
                        loops: Animation.Infinite
                    }
                    property alias albumCanvas: albumCanvasItem
                    Item { id: albumCanvasItem; anchors.fill: parent }
                }

                // EQ bars
                Row {
                    spacing: 4
                    anchors.horizontalCenter: parent.horizontalCenter
                    Repeater {
                        model: 12
                        Rectangle {
                            width: 8
                            height: mediaCtrl.isPlaying ? 8 + Math.random() * 32 : 4
                            radius: 3
                            anchors.bottom: parent.bottom
                            color: root.accent
                            opacity: 0.6 + index * 0.03

                            SequentialAnimation on height {
                                loops: Animation.Infinite
                                running: mediaCtrl.isPlaying
                                NumberAnimation { to: 4 + Math.random() * 40; duration: 200 + index * 30; easing.type: Easing.InOutQuad }
                                NumberAnimation { to: 8 + Math.random() * 20; duration: 300 + index * 20; easing.type: Easing.InOutQuad }
                            }
                        }
                    }
                }
            }

            // ── Right: Controls ───────────────────────────────────────
            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 14

                Item { Layout.fillHeight: true }

                // Track info
                Column {
                    spacing: 4
                    Layout.fillWidth: true
                    Text {
                        text: mediaCtrl.trackTitle
                        color: root.textPrimary
                        font.pixelSize: 22
                        font.family: "Orbitron"
                        font.bold: true
                        elide: Text.ElideRight
                        width: parent.width
                    }
                    Text {
                        text: mediaCtrl.artistName
                        color: root.accent
                        font.pixelSize: 14
                        font.family: "Rajdhani"
                    }
                    Text {
                        text: mediaCtrl.albumName
                        color: root.textDim
                        font.pixelSize: 12
                        font.family: "Rajdhani"
                    }
                }

                // Progress bar
                Column {
                    Layout.fillWidth: true
                    spacing: 6

                    Rectangle {
                        width: parent.width; height: 6; radius: 3
                        color: "#1e1e30"
                        Rectangle {
                            width: parent.width * mediaCtrl.trackProgress
                            height: parent.height; radius: 3
                            color: root.accent
                            Behavior on width { NumberAnimation { duration: 800 } }
                        }
                        // Clickable seek
                        MouseArea {
                            anchors.fill: parent
                            onClicked: (mouse) => mediaCtrl.seekTo(mouse.x / parent.width)
                            cursorShape: Qt.PointingHandCursor
                        }
                    }

                    RowLayout {
                        width: parent.width
                        Text {
                            text: {
                                var t = mediaCtrl.elapsedSec;
                                return Math.floor(t/60) + ":" + String(t%60).padStart(2,"0")
                            }
                            color: root.textDim; font.pixelSize: 11; font.family: "Rajdhani"
                        }
                        Item { Layout.fillWidth: true }
                        Text {
                            text: {
                                var t = mediaCtrl.trackDuration;
                                return Math.floor(t/60) + ":" + String(t%60).padStart(2,"0")
                            }
                            color: root.textDim; font.pixelSize: 11; font.family: "Rajdhani"
                        }
                    }
                }

                // Transport buttons
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12

                    Repeater {
                        model: [
                            { icon: "⏮", action: function() { mediaCtrl.prevTrack() }, primary: false },
                            { icon: mediaCtrl.isPlaying ? "⏸" : "▶",  action: function() { mediaCtrl.playPause() }, primary: true },
                            { icon: "⏭", action: function() { mediaCtrl.nextTrack() }, primary: false },
                        ]
                        delegate: Rectangle {
                            Layout.fillWidth: true
                            height: 50
                            radius: 10
                            color: modelData.primary ? root.accent : root.bgCard
                            border.color: modelData.primary ? "transparent" : "#2a2a44"

                            Text {
                                anchors.centerIn: parent
                                text: modelData.icon
                                font.pixelSize: modelData.primary ? 22 : 18
                                color: modelData.primary ? "#0a0a0f" : root.textPrimary
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: modelData.action()
                                cursorShape: Qt.PointingHandCursor
                            }

                            scale: 1.0
                            Behavior on scale { NumberAnimation { duration: 80 } }
                            MouseArea {
                                anchors.fill: parent
                                onPressed:  parent.scale = 0.93
                                onReleased: { parent.scale = 1.0; modelData.action() }
                                cursorShape: Qt.PointingHandCursor
                            }
                        }
                    }
                }

                // Volume row
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10
                    Text { text: "🔈"; font.pixelSize: 14; color: root.textDim }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 6; radius: 3
                        color: "#1e1e30"
                        Rectangle {
                            width: parent.width * (mediaCtrl.volume / 100)
                            height: parent.height; radius: 3
                            color: root.accentAmber
                            Behavior on width { NumberAnimation { duration: 200 } }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: (mouse) => mediaCtrl.setVolume(Math.round(mouse.x / parent.width * 100))
                            cursorShape: Qt.PointingHandCursor
                        }
                    }
                    Text { text: "🔊"; font.pixelSize: 14; color: root.textDim }
                    Text { text: mediaCtrl.volume + "%"; color: root.accentAmber; font.pixelSize: 13; font.family: "Orbitron"; width: 40 }
                }

                // Track list
                Column {
                    Layout.fillWidth: true
                    spacing: 4
                    Repeater {
                        model: mediaCtrl.totalTracks
                        delegate: Rectangle {
                            width: parent.width; height: 30; radius: 6
                            color: index === mediaCtrl.trackIndex ? "#1a2a3a" : "transparent"
                            border.color: index === mediaCtrl.trackIndex ? root.accent : "transparent"
                            border.width: 1
                            Row {
                                anchors { left: parent.left; leftMargin: 10; verticalCenter: parent.verticalCenter }
                                spacing: 8
                                Text {
                                    text: (index + 1) + "."
                                    color: root.textDim; font.pixelSize: 11; font.family: "Orbitron"
                                }
                                Text {
                                    text: ["Neon Highways","Midnight Cruise","Speed of Light","Urban Drift","Pulse of the Road"][index]
                                    color: index === mediaCtrl.trackIndex ? root.accent : root.textPrimary
                                    font.pixelSize: 12; font.family: "Rajdhani"
                                }
                            }
                            Text {
                                anchors { right: parent.right; rightMargin: 10; verticalCenter: parent.verticalCenter }
                                text: ["3:34","3:07","4:13","3:18","3:51"][index]
                                color: root.textDim; font.pixelSize: 11; font.family: "Rajdhani"
                            }
                            MouseArea { anchors.fill: parent; onClicked: { while(mediaCtrl.trackIndex !== index) mediaCtrl.nextTrack() } }
                        }
                    }
                }

                Item { Layout.fillHeight: true }
            }
        }
    }
}
