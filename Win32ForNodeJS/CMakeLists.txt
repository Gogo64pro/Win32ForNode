cmake_minimum_required(VERSION 3.24)
project(Win32ForNode)

set(CMAKE_CXX_STANDARD 17)

add_library(Win32ForNode SHARED fake.cpp constants.h++ functions.h++ internalfunctions.h++)

add_custom_target(build_addon
        COMMAND node-gyp build
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Building Node.js addon"
        )
add_dependencies(Win32ForNode build_addon)
include_directories(
        C:/MinGW/x86_64-w64-mingw32/include/
)