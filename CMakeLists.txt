cmake_minimum_required(VERSION 3.16)

project(ISADO C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
    boot
    kernel
    core
    logger
    shell
    system
    ui
    gui
    launcher
    wm
    process

    ${SDL2_INCLUDE_DIRS}
)

link_directories(${SDL2_LIBRARY_DIRS})

add_executable(isado

    # Boot
    boot/boot_manager.c

    # Kernel
    kernel/kernel.c

    # Core
    core/core.c
    core/config.c

    # Logger
    logger/logger.c

    # Shell
    shell/isado_shell.c
    shell/parser.c
    shell/commands.c

    # System
    system/system.c

    # Process
    process/process.c

    # GUI
    gui/gui.c
    gui/main_window.c
    gui/mouse.c
    gui/keyboard.c
    
    # UI
    ui/theme.c
    ui/draw.c
    
    # Launcher
    launcher/desktop.c
    launcher/wallpaper.c
    launcher/icons.c
    launcher/dock.c
    
    # Window Manager
    wm/window.c
    wm/window_manager.c
)

target_link_libraries(
    isado
    ${SDL2_LIBRARIES}
)