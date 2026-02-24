import QtQuick
import QtQuick.Layouts

// Navigation mock screen
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
            anchors.fill: parent
            anchors.margins: 16
            spacing: 12

            // ── Direction card ─────────────────────────────────────
            Rectangle {
                Layout.fillWidth: true
                height: 80
                radius: 12
                color: root.bgCard
                border.color: root.accent
                border.width: 1

                RowLayout {
                    anchors { fill: parent; margins: 14 }
                    spacing: 16

                    // Direction arrow icon
                    Rectangle {
                        width: 52; height: 52; radius: 10
                        color: root.accent

                        Text {
                            anchors.centerIn: parent
                            text: navCtrl.directionIcon === "turn-right"  ? "➡" :
                                  navCtrl.directionIcon === "turn-left"   ? "⬅" :
                                  navCtrl.directionIcon === "keep-left"   ? "↖" :
                                  navCtrl.directionIcon === "destination" ? "📍" : "⬆"
                            font.pixelSize: 26
                            color: "#0a0a0f"
                        }
                    }

                    Column {
                        Layout.fillWidth: true
                        spacing: 4
                        Text {
                            text: navCtrl.nextManeuver
                            color: root.textPrimary
                            font.pixelSize: 13
                            font.family: "Rajdhani"
                            elide: Text.ElideRight
                            width: parent.width
                        }
                        Text {
                            text: navCtrl.currentStreet
                            color: root.textDim
                            font.pixelSize: 11
                            font.family: "Rajdhani"
                        }
                    }

                    Column {
                        spacing: 4
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: navCtrl.distanceToNext.toFixed(1) + " km"
                            color: root.accent
                            font.pixelSize: 18
                            font.family: "Orbitron"
                            font.bold: true
                        }
                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: "ETA " + navCtrl.etaMinutes + " min"
                            color: root.accentAmber
                            font.pixelSize: 11
                            font.family: "Rajdhani"
                        }
                    }
                }
            }

            // ── Mock Map Canvas ────────────────────────────────────
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                radius: 12
                color: "#0f1a0f"
                clip: true

                Canvas {
                    id: mapCanvas
                    anchors.fill: parent

                    // Watch navCtrl properties to redraw
                    property real carX: navCtrl.carX
                    property real carY: navCtrl.carY
                    onCarXChanged: requestPaint()
                    onCarYChanged: requestPaint()

                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.reset();
                        var W = width, H = height;

                        // Background — dark map
                        ctx.fillStyle = "#0f1a0f";
                        ctx.fillRect(0, 0, W, H);

                        // Grid lines (city blocks)
                        ctx.strokeStyle = "#1a2a1a";
                        ctx.lineWidth = 1;
                        for (var x = 0; x < W; x += 40) {
                            ctx.beginPath(); ctx.moveTo(x, 0); ctx.lineTo(x, H); ctx.stroke();
                        }
                        for (var y = 0; y < H; y += 40) {
                            ctx.beginPath(); ctx.moveTo(0, y); ctx.lineTo(W, y); ctx.stroke();
                        }

                        // Streets (polyline segments)
                        var streets = [
                            { x1: 0.10, y1: 0.75, x2: 0.25, y2: 0.75, w: 4 },
                            { x1: 0.25, y1: 0.75, x2: 0.25, y2: 0.45, w: 4 },
                            { x1: 0.25, y1: 0.45, x2: 0.55, y2: 0.45, w: 4 },
                            { x1: 0.55, y1: 0.45, x2: 0.70, y2: 0.30, w: 4 },
                            { x1: 0.70, y1: 0.30, x2: 0.88, y2: 0.30, w: 4 },
                            // extra roads
                            { x1: 0.0,  y1: 0.30, x2: 1.0,  y2: 0.30, w: 2 },
                            { x1: 0.0,  y1: 0.60, x2: 1.0,  y2: 0.60, w: 2 },
                            { x1: 0.40, y1: 0.0,  x2: 0.40, y2: 1.0,  w: 2 },
                            { x1: 0.60, y1: 0.0,  x2: 0.60, y2: 1.0,  w: 2 },
                        ];

                        streets.forEach(function(s) {
                            ctx.beginPath();
                            ctx.moveTo(s.x1 * W, s.y1 * H);
                            ctx.lineTo(s.x2 * W, s.y2 * H);
                            ctx.strokeStyle = s.w > 2 ? "#2a4a2a" : "#1e2e1e";
                            ctx.lineWidth   = s.w;
                            ctx.stroke();
                        });

                        // Route highlight
                        var route = [
                            [0.10, 0.75], [0.25, 0.75], [0.25, 0.45],
                            [0.55, 0.45], [0.70, 0.30], [0.88, 0.30]
                        ];
                        // Glow route
                        ctx.beginPath();
                        ctx.moveTo(route[0][0]*W, route[0][1]*H);
                        for (var i = 1; i < route.length; i++)
                            ctx.lineTo(route[i][0]*W, route[i][1]*H);
                        ctx.strokeStyle = "rgba(0,212,255,0.25)";
                        ctx.lineWidth = 14;
                        ctx.lineJoin  = "round";
                        ctx.stroke();

                        ctx.beginPath();
                        ctx.moveTo(route[0][0]*W, route[0][1]*H);
                        for (var j = 1; j < route.length; j++)
                            ctx.lineTo(route[j][0]*W, route[j][1]*H);
                        ctx.strokeStyle = "#00d4ff";
                        ctx.lineWidth = 3;
                        ctx.stroke();

                        // Waypoint dots
                        route.forEach(function(pt, idx) {
                            ctx.beginPath();
                            ctx.arc(pt[0]*W, pt[1]*H, idx === route.length-1 ? 8 : 4, 0, Math.PI*2);
                            ctx.fillStyle = idx === route.length-1 ? "#ff8c00" : "#00d4ff";
                            ctx.shadowColor = idx === route.length-1 ? "#ff8c00" : "#00d4ff";
                            ctx.shadowBlur  = 10;
                            ctx.fill();
                            ctx.shadowBlur = 0;
                        });

                        // Car indicator
                        var cx = mapCanvas.carX * W;
                        var cy = mapCanvas.carY * H;
                        ctx.beginPath();
                        ctx.arc(cx, cy, 9, 0, Math.PI*2);
                        ctx.fillStyle = "#ffffff";
                        ctx.shadowColor = "#ffffff";
                        ctx.shadowBlur  = 16;
                        ctx.fill();
                        ctx.shadowBlur = 0;

                        ctx.beginPath();
                        ctx.arc(cx, cy, 5, 0, Math.PI*2);
                        ctx.fillStyle = "#ff2d55";
                        ctx.fill();
                    }
                }

                // Destination label
                Text {
                    anchors { right: parent.right; top: parent.top; margins: 12 }
                    text: "📍 " + navCtrl.destination
                    color: root.accentAmber
                    font.pixelSize: 11
                    font.family: "Orbitron"
                }
            }

            // ── Bottom row: start/stop + progress ─────────────────
            RowLayout {
                Layout.fillWidth: true
                spacing: 12

                Rectangle {
                    Layout.preferredWidth: 140; height: 44; radius: 10
                    color: navCtrl.isNavigating ? root.accentRed : root.accent

                    Text {
                        anchors.centerIn: parent
                        text: navCtrl.isNavigating ? "⏹  Stop" : "▶  Start Route"
                        color: "#0a0a0f"
                        font.pixelSize: 13; font.family: "Orbitron"; font.bold: true
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: navCtrl.isNavigating ? navCtrl.stopRoute() : navCtrl.startRoute()
                        cursorShape: Qt.PointingHandCursor
                    }
                }

                // Route progress bar
                Column {
                    Layout.fillWidth: true
                    spacing: 4
                    Text { text: "Route Progress"; color: root.textDim; font.pixelSize: 10; font.family: "Rajdhani" }
                    Rectangle {
                        width: parent.width; height: 8; radius: 4
                        color: "#1e1e30"
                        Rectangle {
                            width: parent.width * navCtrl.routeProgress
                            height: parent.height; radius: 4; color: root.accent
                            Behavior on width { NumberAnimation { duration: 300 } }
                        }
                    }
                    Text { text: Math.round(navCtrl.routeProgress * 100) + "% complete"; color: root.textDim; font.pixelSize: 10; font.family: "Rajdhani" }
                }
            }
        }
    }
}
