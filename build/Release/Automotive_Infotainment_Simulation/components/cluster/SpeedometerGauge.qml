import QtQuick

// Arc-based Speedometer — 0 to 220 km/h
Item {
    id: root

    property double speed: vehicleCtrl.speed
    property color  accent:      "#00d4ff"
    property color  accentAmber: "#ff8c00"
    property color  bgCard:      "#1a1a2e"
    property color  textPrimary: "#e8e8f0"
    property color  textDim:     "#7a7a9a"

    implicitWidth:  260
    implicitHeight: 260

    // Animated speed value (smooth)
    property double animSpeed: 0
    Behavior on animSpeed { NumberAnimation { duration: 200; easing.type: Easing.OutQuad } }
    onSpeedChanged: animSpeed = speed

    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            var cx = width / 2, cy = height / 2;
            var r = Math.min(width, height) / 2 - 10;

            var startAngle = Math.PI * 0.75;
            var endAngle   = Math.PI * 2.25;
            var range      = endAngle - startAngle;

            // Background arc
            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, endAngle);
            ctx.strokeStyle = "#1e1e30";
            ctx.lineWidth   = 16;
            ctx.stroke();

            // Coloured arc fill
            var fraction = Math.min(root.animSpeed / 220.0, 1.0);
            var fillColor = root.animSpeed > 160 ? root.accentAmber :
                            root.animSpeed > 200 ? "#e74c3c" : root.accent;
            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, startAngle + fraction * range);
            ctx.strokeStyle = fillColor;
            ctx.lineWidth   = 16;
            ctx.lineCap     = "round";
            ctx.stroke();

            // Glow layer
            ctx.shadowColor = fillColor;
            ctx.shadowBlur  = 18;
            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, startAngle + fraction * range);
            ctx.strokeStyle = fillColor;
            ctx.lineWidth   = 4;
            ctx.stroke();
            ctx.shadowBlur = 0;

            // Tick marks
            var steps = 22;
            for (var i = 0; i <= steps; i++) {
                var a = startAngle + (i / steps) * range;
                var isMajor = (i % 2 === 0);
                var len = isMajor ? 12 : 6;
                var r1 = r - 20, r2 = r1 - len;
                ctx.beginPath();
                ctx.moveTo(cx + Math.cos(a) * r1, cy + Math.sin(a) * r1);
                ctx.lineTo(cx + Math.cos(a) * r2, cy + Math.sin(a) * r2);
                ctx.strokeStyle = isMajor ? "#4a4a6a" : "#2a2a44";
                ctx.lineWidth   = isMajor ? 2 : 1;
                ctx.stroke();
            }
        }
    }
    // Redraw when speed changes
    Connections { target: vehicleCtrl; function onSpeedChanged() { canvas.requestPaint() } }

    // Speed number
    Text {
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter; verticalCenterOffset: -10 }
        text: Math.round(root.animSpeed)
        color: root.textPrimary
        font.pixelSize: 52
        font.family: "Orbitron"
        font.bold: true

        Behavior on text {}     // suppress default animation on string
    }

    Text {
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.verticalCenter; bottomMargin: -42 }
        text: "km/h"
        color: root.accent
        font.pixelSize: 13
        font.family: "Rajdhani"
        font.letterSpacing: 2
    }

    // Speed label
    Text {
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 28 }
        text: "SPEED"
        color: root.textDim
        font.pixelSize: 10
        font.family: "Orbitron"
        font.letterSpacing: 3
    }
}
