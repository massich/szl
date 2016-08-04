# Define project name
project("szl" CXX)

# cmake needs this line
cmake_minimum_required(VERSION 3.3)

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
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#
## Find Boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Add project libraries
add_subdirectory(src/common/)

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/")

#targets
set(EXEC_NAME main)
add_executable(${EXEC_NAME} ./src/main.cpp)

# set(EXAMPLE daytime)
# add_executable(${EXAMPLE} ./src/examples/daytime.cpp)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(foo ./src/examples/daytime.cpp)
  target_link_libraries(foo ${Boost_LIBRARIES})
endif()

set(APP_DEPS
    common
    )

target_link_libraries(${EXEC_NAME} common)
# target_link_libraries(${EXAMPLE} ${Boost_LIBRARIES})

add_executable(gtest_test ./src/test_test.cpp)

set(
    TESTS_DEPS
    ${APP_DEPS}
    ${GTEST_LIBRARIES}
    )

target_link_libraries(gtest_test ${TESTS_DEPS})

# verbose cmake variable status
if(CMAKE_VERBOSE)
  include(src/cmake/verbose_config.cmake)
endif()
