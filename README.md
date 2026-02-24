# Automotive Infotainment Simulation

A cross-platform **Digital Cockpit + Infotainment System Simulator** built with **Qt 6 / QML** and **C++**, 
designed to mimic a real-world in-car dashboard experience.

## Features

-  **Vehicle Dashboard** — Live speedometer, RPM cluster, gear indicator, and fuel level display
-  **Media Player** — Play/pause, track navigation, and volume control simulation
-  **Navigation Screen** — Mock navigation UI with route and destination display
-  **Bluetooth Controller** — Device pairing simulation and connection state management
-  **Vehicle Alerts** — Real-time warning and alert system (engine, fuel, temperature, etc.)
-  **Real-time Data Updates** — Signals & Slots-driven UI updates from the C++ controller layer
-  **State Machine Logic** — Screen switching and command routing via QML + C++ state management

## Tech Stack

- **Qt 6 / QML** — UI rendering and declarative component design
- **C++** — Backend controller layer (`VehicleController`, `MediaController`, `NavigationController`, `BluetoothController`)
- **CMake** — Build system
