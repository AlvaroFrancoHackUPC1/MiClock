# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MiClock_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MiClock_autogen.dir/ParseCache.txt"
  "MiClock_autogen"
  )
endif()
