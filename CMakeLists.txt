cmake_minimum_required(VERSION 3.16)
project(tyrlib C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB_RECURSE TYRLIB_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tyrlib/*.c"
)

add_library(tyrlib ${TYRLIB_SOURCES})

target_include_directories(tyrlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tyrlib/include
)

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

option(TYRLIB_BUILD_BENCHMARKS "Build benchmarks" OFF)

if(TYRLIB_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()
