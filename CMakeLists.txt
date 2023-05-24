cmake_minimum_required(VERSION 3.24)
# If you can help me fix this please do so
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
        C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/VC/Tools/MSVC/14.29.30133/include/
)
add_custom_command(
        OUTPUT build/Release/addon.node
        COMMAND node-gyp rebuild
        COMMENT "Rebuilding"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
