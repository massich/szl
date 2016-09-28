find_package(Git REQUIRED)
if(GIT_FOUND)
  message("git found: ${GIT_EXECUTABLE}")
endif()

## External Libraries (either find them or install them using git)

set(EP_PREFIX "src/third_party")

find_package(GTest)
if (NOT GTest_FOUND)
  include(src/cmake/download_gtest.cmake REQUIRED)
else(NOT GTest_FOUND)
  include_directories(${GTEST_INCLUDE_DIRS})
endif(NOT GTest_FOUND)
