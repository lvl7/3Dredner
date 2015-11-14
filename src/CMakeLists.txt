set(module_name 3DRender)
project(${module_name} CXX)

find_package(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

file(GLOB includes
    ${CMAKE_SOURCE_DIR}/include/visualisation/example/*.h
    ${CMAKE_SOURCE_DIR}/include/calculation/*.h
)

set(all_includes ${includes})


# 'file(GLOB' let search all *.cpp files
file(GLOB sources
	${CMAKE_CURRENT_SOURCE_DIR}/visualisation/example/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/calculation/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(all_sources ${sources})

add_executable(${module_name} ${all_sources} ${all_includes})

target_link_libraries(${module_name} ${VTK_LIBRARIES})

set(gcc_warnings
    -Wall
    -Wextra
# VTK has problem with this flag:
#    -Wpedantic
#    -Weffc++
    )

set(gcc_muted_warnings
    )

add_gcc_flags("${gcc_warnings} ${gcc_muted_warnings} -Werror")
