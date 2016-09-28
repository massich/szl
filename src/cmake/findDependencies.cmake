# This cmake find the external libraries needed. In case they are not pressent,
# these libraries are downloaded and compiled to be used by the project.
# (More info regarding ExternalProjects can be found [here](https://cmake.org/cmake/help/v3.0/module/ExternalProject.html))
#

# Enable ExternalProject CMake module
include(ExternalProject)

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add GIT tool to manage donwloading, etc..
find_package(Git REQUIRED)
if(GIT_FOUND)
  message("git found: ${GIT_EXECUTABLE}")
endif()

###
#   Add GTest
###########################################
# find_package(GTest)
# if (NOT GTest_FOUND)
#   include(src/cmake/download_gtest.cmake REQUIRED)
# endif(NOT GTest_FOUND)
# include_directories(${GTEST_INCLUDE_DIRS})

# TODO: uncomment find_package
include(src/cmake/download_gtest.cmake REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
