# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tst_bluetoothcontroller_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tst_bluetoothcontroller_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\tst_mediacontroller_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tst_mediacontroller_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\tst_navigationcontroller_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tst_navigationcontroller_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\tst_vehiclecontroller_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tst_vehiclecontroller_autogen.dir\\ParseCache.txt"
  "tst_bluetoothcontroller_autogen"
  "tst_mediacontroller_autogen"
  "tst_navigationcontroller_autogen"
  "tst_vehiclecontroller_autogen"
  )
endif()
