find_package(Git REQUIRED)
if(GIT_FOUND)
  message("git found: ${GIT_EXECUTABLE}")
endif()

include(src/cmake/find_or_download_gtest.cmake REQUIRED)
