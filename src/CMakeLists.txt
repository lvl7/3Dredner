set(module_name main)
project(${module_name} CXX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/calcualtion/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/format/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/visualisation/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/world/*.h
)

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/calcualtion/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/format/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/visualisation/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/world/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

set(all_sources ${sources})

add_executable(${module_name} ${all_sources})

set(gcc_warnings
    -Wall
    -Wextra
    -Wpedantic
    -Weffc++
    )

set(gcc_muted_warnings
    )

add_gcc_flags("${gcc_warnings} ${gcc_muted_warnings} -Werror")
