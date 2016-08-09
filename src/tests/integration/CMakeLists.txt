file(GLOB_RECURSE itesting_sources *.cpp *.cc)
file(GLOB_RECURSE itesting_headers *.h *.hpp)

set( SRCS_ITEST_ALL
     ${itesting_sources}
     ${itesting_headers}
)
