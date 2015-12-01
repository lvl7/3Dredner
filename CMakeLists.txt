cmake_minimum_required(VERSION 2.8)
project(3DRender_project C CXX)

set(CMAKE_COMPILER gcc)
add_compile_options(-std=c++11)

if("${CMAKE_COMPILER}" STREQUAL "")
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_COMPILER g++)
    elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        set(CMAKE_COMPILER clang)
    endif()
endif()

function(add_gcc_flags flags)
    # ignore non-gcc
    if(NOT "${CMAKE_COMPILER}" STREQUAL "gcc")
        return()
    endif()

    message(STATUS "  adding gcc flags: ${flags}")
    add_definitions(${flags})
endfunction()

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
#add_subdirectory(test)
#add_subdirectory(lib)

