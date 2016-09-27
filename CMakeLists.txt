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
# option(CMAKE_EXTERNAL_LIBRARIES_PATH "Where to download and install libraries if not present (relative path)" "src/third_party/")
set(CMAKE_EXTERNAL_LIBRARIES_PATH "src/third_party/")

####
# Load Compiler Flags and options
include(src/cmake/compiler_definition_options.cmake REQUIRED)
####

####
# Dependences
include(src/cmake/findDependencies.cmake REQUIRED)
####


# # Add project libraries
# add_subdirectory(src/common/)

# INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/")

# #targets
# set(EXEC_NAME main)
# add_executable(${EXEC_NAME} ./src/main.cpp)

# set(APP_DEPS
#     common
#     )

# target_link_libraries(${EXEC_NAME} common)

# # test
# add_subdirectory(src/tests)

# # verbose cmake variable status
# if(CMAKE_VERBOSE)
#   include(src/cmake/verbose_config.cmake)
# endif()
