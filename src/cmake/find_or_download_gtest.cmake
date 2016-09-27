## Find Google Test
find_package(GTest)

if (NOT GTest_FOUND)
  message("GTest not found")

else(NOT GTest_FOUND)
  message("Gtest found: ${GTEST_INCLUDE_DIRS}")
  include_directories(${GTEST_INCLUDE_DIRS})

endif(NOT GTest_FOUND)
