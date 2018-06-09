cmake_minimum_required(VERSION 3.10)

# Options. Turn on with 'cmake -D{VAR}=ON'
option(test "Build tests" OFF)
option(verbose "Verbose build output" OFF)

if (verbose)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

project(DrMario)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_subdirectory(src/main)
if (test)
    add_subdirectory(src/test)
endif()