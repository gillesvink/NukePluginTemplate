# Allows global toolchain to be set using GLOBAL_TOOLCHAIN env
# Note: needs to happen before project is set
if(DEFINED ENV{GLOBAL_TOOLCHAIN})
    message("Set toolchain $ENV{GLOBAL_TOOLCHAIN}")
    set(CMAKE_TOOLCHAIN_FILE $ENV{GLOBAL_TOOLCHAIN})
endif()

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(NukePluginTemplate)

set(CMAKE_MODULE_PATH "CMake;${CMAKE_MODULE_PATH}")
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

find_package(Nuke REQUIRED)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

function(add_plugin PLUGIN_NAME)
    add_nuke_plugin(${PLUGIN_NAME} ${ARGN})
    target_compile_definitions(${PLUGIN_NAME} PRIVATE FN_PLUGIN)
endfunction()

add_plugin(Multiply src/Multiply.cpp)