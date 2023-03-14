# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Layouts_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Layouts_autogen.dir\\ParseCache.txt"
  "Layouts_autogen"
  )
endif()
