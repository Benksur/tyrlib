cmake_minimum_required(VERSION 3.16)
project(tyrlib C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(tyrlib tyrlib/arena.c)

target_include_directories(tyrlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tyrlib/include
)
