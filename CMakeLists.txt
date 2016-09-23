# Define project name
project("szl" CXX)

# cmake needs this line
cmake_minimum_required(VERSION 2.8)

####
# CMake configuration
# include(src/cmake/options.cmake REQUIRED
####
# Load CMake configuration flags. Those can be modified using `ccmake`
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
option(WARNINGS_AS_ERRORS   "Compiler warnings as errors"        "ON")
option(OPT_ASAN             "Use adress sanitizer (debug)"       "ON")
option(CMAKE_VERBOSE        "Show a verbose CMake configuration" "ON")

####
# Load Compiler Flags and options
include(src/cmake/compiler_definition_options.cmake REQUIRED)
####

####
# Dependences
# include(src/cmake/findDependencies.cmake REQUIRED)
####
# Load code dependencies and their configuration
#
## Find Google Test
# find_package(GTest)
# if (NOT GTest_FOUND)
  set(GTEST_ROOT src/third_party/googletest/googletest CACHE STRING "Google Test source root")

  include_directories(
      ${PROJECT_SOURCE_DIR}/${GTEST_ROOT}
      ${PROJECT_SOURCE_DIR}/${GTEST_ROOT}/include
      )

  set(GTEST_SOURCES
      ${PROJECT_SOURCE_DIR}/${GTEST_ROOT}/src/gtest-all.cc
      ${PROJECT_SOURCE_DIR}/${GTEST_ROOT}/src/gtest_main.cc
      )

  foreach(_source ${GTEST_SOURCES})
      set_source_files_properties(${_source} PROPERTIES GENERATED 1)
  endforeach()

  add_library(GTest ${GTEST_SOURCES})
# else()
#   include_directories(${GTEST_INCLUDE_DIRS})
# endif()



# Add project libraries
add_subdirectory(src/common/)

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/")

#targets
set(EXEC_NAME main)
add_executable(${EXEC_NAME} ./src/main.cpp)

set(APP_DEPS
    common
    )

target_link_libraries(${EXEC_NAME} common)

# test
add_subdirectory(src/tests)

# verbose cmake variable status
if(CMAKE_VERBOSE)
  include(src/cmake/verbose_config.cmake)
endif()
