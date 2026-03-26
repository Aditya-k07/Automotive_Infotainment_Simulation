import QtQuick

// Arc-based RPM gauge — 0 to 8000 RPM
Item {
    id: root

    property double rpm:         vehicleCtrl.rpm
    property color  accent:      "#00d4ff"
    property color  accentAmber: "#ff8c00"
    property color  accentRed:   "#e74c3c"
    property color  bgCard:      "#1a1a2e"
    property color  textPrimary: "#e8e8f0"
    property color  textDim:     "#7a7a9a"

    implicitWidth:  200
    implicitHeight: 200

    property double animRpm: 0
    Behavior on animRpm { NumberAnimation { duration: 150; easing.type: Easing.OutQuad } }
    onRpmChanged: animRpm = rpm

    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            var cx = width / 2, cy = height / 2;
            var r  = Math.min(width, height) / 2 - 8;
            var startAngle = Math.PI * 0.75;
            var endAngle   = Math.PI * 2.25;
            var range      = endAngle - startAngle;

            // Background
            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, endAngle);
            ctx.strokeStyle = "#1e1e30";
            ctx.lineWidth   = 12;
            ctx.stroke();

            // Red zone (6500-8000)
            var redStart = startAngle + (6500 / 8000) * range;
            ctx.beginPath();
            ctx.arc(cx, cy, r, redStart, endAngle);
            ctx.strokeStyle = "#3a1010";
            ctx.lineWidth   = 12;
            ctx.stroke();

            // Fill arc
            var fraction = Math.min(root.animRpm / 8000.0, 1.0);
            var fillColor = root.animRpm > 6500 ? root.accentRed :
                            root.animRpm > 5000 ? root.accentAmber : root.accent;
            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, startAngle + fraction * range);
            ctx.strokeStyle = fillColor;
            ctx.lineWidth   = 12;
            ctx.lineCap     = "round";
            ctx.shadowColor = fillColor;
            ctx.shadowBlur  = 14;
            ctx.stroke();
            ctx.shadowBlur = 0;
        }
    }
    Connections { target: vehicleCtrl; function onRpmChanged() { canvas.requestPaint() } }

    Text {
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter; verticalCenterOffset: -6 }
        text: Math.round(root.animRpm)
        color: root.animRpm > 6500 ? root.accentRed : root.textPrimary
        font.pixelSize: 30
        font.family: "Orbitron"
        font.bold: true
    }

    Text {
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.verticalCenter; bottomMargin: -28 }
        text: "RPM"
        color: root.textDim
        font.pixelSize: 10
        font.family: "Orbitron"
        font.letterSpacing: 3
    }
}
