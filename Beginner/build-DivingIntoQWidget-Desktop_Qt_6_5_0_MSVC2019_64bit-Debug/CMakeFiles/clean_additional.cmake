# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DivingIntoQWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DivingIntoQWidget_autogen.dir\\ParseCache.txt"
  "DivingIntoQWidget_autogen"
  )
endif()
