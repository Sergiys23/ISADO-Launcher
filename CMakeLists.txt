cmake_minimum_required(VERSION 3.16)

project(ISADO C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(
    boot
    core
    kernel
    shell
    gui
    graphics
    launcher
    wm
    apps
    apps/browser
    apps/explorer
    apps/settings
    apps/terminal
    ${SDL2_INCLUDE_DIRS}
)

link_directories(${SDL2_LIBRARY_DIRS})

add_definitions(-DSDL_MAIN_HANDLED)

file(GLOB_RECURSE SOURCES
    boot/*.c
    core/*.c
    kernel/*.c
    shell/*.c
    gui/*.c
    graphics/*.c
    launcher/*.c
    wm/*.c
    apps/*.c
)

add_executable(isado ${SOURCES})

target_link_libraries(isado
    ${SDL2_LIBRARIES}
)