import QtQuick
import QtQuick.Window

Window {
    id: root
    width: 1280
    height: 720
    minimumWidth: 1280
    minimumHeight: 720
    visible: true
    title: "Automotive Infotainment System"
    color: "#0a0a0f"

    FontLoader { id: orbitronFont;  source: "https://fonts.gstatic.com/s/orbitron/v31/yMJMMIlzdpvBhQQL_SC3X9yhF25-T1nyGy6xpmIyXjU1pg.woff2" }
    FontLoader { id: rajdhaniFont;  source: "https://fonts.gstatic.com/s/rajdhani/v16/LDIxapCSOBg7S-QT7pasEenI.woff2" }

    DashboardView {
        anchors.fill: parent
    }
}
