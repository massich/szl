include(CTest)
file(GLOB_RECURSE tst_sources *.cpp *.cc)
file(GLOB_RECURSE tst_headers *.h *.hpp)

set( SRC_TESTS
     ${tst_sources}
     ${tst_headers}
)

add_executable(gtest_test test_test.cpp ${SRC_TESTS})

set(
    TESTS_DEPS
    ${APP_DEPS}
    ${GTEST_LIBRARIES}
    )

target_link_libraries(gtest_test gtest ${TESTS_DEPS})

add_test(NAME gtest_test COMMAND gtest_test)
