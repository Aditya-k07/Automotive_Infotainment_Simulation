cmake_minimum_required(VERSION 3.16)

project(Automotive_Infotainment_Simulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appAutomotive_Infotainment_Simulation
    main.cpp
    VehicleController.cpp    VehicleController.h
    MediaController.cpp      MediaController.h
    NavigationController.cpp NavigationController.h
    BluetoothController.cpp  BluetoothController.h
)

qt_add_qml_module(appAutomotive_Infotainment_Simulation
    URI Automotive_Infotainment_Simulation
    QML_FILES
        Main.qml
        DashboardView.qml
        components/cluster/InstrumentCluster.qml
        components/cluster/SpeedometerGauge.qml
        components/cluster/RPMGauge.qml
        components/cluster/FuelGauge.qml
        components/cluster/TempGauge.qml
        components/cluster/WarningLights.qml
        components/infotainment/InfotainmentPanel.qml
        components/infotainment/MediaPlayer.qml
        components/infotainment/NavigationScreen.qml
        components/infotainment/SettingsScreen.qml
        components/infotainment/PhoneScreen.qml
)

set_target_properties(appAutomotive_Infotainment_Simulation PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAutomotive_Infotainment_Simulation
    PRIVATE Qt6::Quick Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appAutomotive_Infotainment_Simulation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
