file(GLOB_RECURSE utesting_sources *.cpp *.cc)
file(GLOB_RECURSE utesting_headers *.h *.hpp)

set( SRCS_UTEST_ALL
     ${utesting_sources}
     ${utesting_headers}
)
