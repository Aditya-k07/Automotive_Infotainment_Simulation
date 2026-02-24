# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appAutomotive_Infotainment_Simulation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appAutomotive_Infotainment_Simulation_autogen.dir\\ParseCache.txt"
  "appAutomotive_Infotainment_Simulation_autogen"
  )
endif()
