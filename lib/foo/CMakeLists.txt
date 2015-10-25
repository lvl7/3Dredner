set(module_name foo)
project(${module_name} CXX)

message(STATUS "Configuring ${module_name}")

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/foo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/foo.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interfaces/IFoo.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interfaces/IPrintable.h
)

add_library(${module_name} STATIC ${sources})

set(gcc_warnings
    -pedantic
    -Wall
    -Wextra
    -Weffc++
    )
	
set(gcc_muted_warnings
    )
	
add_gcc_flags("${gcc_warnings} ${gcc_muted_warnings} -Werror")

target_include_directories(${module_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
