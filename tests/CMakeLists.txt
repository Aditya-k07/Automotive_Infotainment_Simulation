cmake_minimum_required(VERSION 3.16)

project(Automotive_Infotainment_Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

# Source directory of the main project
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")

# ── VehicleController Tests ──────────────────────────────────────────────
add_executable(tst_vehiclecontroller
    tst_vehiclecontroller.cpp
    ${SRC_DIR}/VehicleController.cpp
    ${SRC_DIR}/VehicleController.h
)
target_include_directories(tst_vehiclecontroller PRIVATE ${SRC_DIR})
target_link_libraries(tst_vehiclecontroller PRIVATE Qt6::Core Qt6::Test)
add_test(NAME VehicleControllerTest COMMAND tst_vehiclecontroller)

# ── MediaController Tests ────────────────────────────────────────────────
add_executable(tst_mediacontroller
    tst_mediacontroller.cpp
    ${SRC_DIR}/MediaController.cpp
    ${SRC_DIR}/MediaController.h
)
target_include_directories(tst_mediacontroller PRIVATE ${SRC_DIR})
target_link_libraries(tst_mediacontroller PRIVATE Qt6::Core Qt6::Test)
add_test(NAME MediaControllerTest COMMAND tst_mediacontroller)

# ── NavigationController Tests ───────────────────────────────────────────
add_executable(tst_navigationcontroller
    tst_navigationcontroller.cpp
    ${SRC_DIR}/NavigationController.cpp
    ${SRC_DIR}/NavigationController.h
)
target_include_directories(tst_navigationcontroller PRIVATE ${SRC_DIR})
target_link_libraries(tst_navigationcontroller PRIVATE Qt6::Core Qt6::Test)
add_test(NAME NavigationControllerTest COMMAND tst_navigationcontroller)

# ── BluetoothController Tests ───────────────────────────────────────────
add_executable(tst_bluetoothcontroller
    tst_bluetoothcontroller.cpp
    ${SRC_DIR}/BluetoothController.cpp
    ${SRC_DIR}/BluetoothController.h
)
target_include_directories(tst_bluetoothcontroller PRIVATE ${SRC_DIR})
target_link_libraries(tst_bluetoothcontroller PRIVATE Qt6::Core Qt6::Test)
add_test(NAME BluetoothControllerTest COMMAND tst_bluetoothcontroller)

enable_testing()
