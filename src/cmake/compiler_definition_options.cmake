set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#set (CMAKE_CXX_FLAGS                "-std=c++14 -Wextra -Wall -Wno-delete-non-virtual-dtor -Werror=return-type")
set (CMAKE_CXX_FLAGS_DEBUG          "-g -O0 -DDEBUG")
set (CMAKE_CXX_FLAGS_RELEASE        "-O3")

if(WARNINGS_AS_ERRORS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

if(OPT_ASAN)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")

    if(NOT EXISTS ${CMAKE_CXX_COMPILER})
        message( FATAL_ERROR "Clang++ not found. " )
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-register -Qunused-arguments")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-const-variable")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")

endif()
