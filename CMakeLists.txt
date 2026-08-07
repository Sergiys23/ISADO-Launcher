cmake_minimum_required(VERSION 3.16)

project(ISADO LANGUAGES C CXX)

# =====================================================
# Standards
# =====================================================

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =====================================================
# SDL
# =====================================================

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2TTF REQUIRED SDL2_ttf)

add_definitions(-DSDL_MAIN_HANDLED)

# =====================================================
# Source files
# =====================================================

file(GLOB_RECURSE ISADO_C_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.c"
)

file(GLOB_RECURSE ISADO_CPP_SOURCES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.cpp"
)

# =====================================================
# Remove build directories
# =====================================================

foreach(dir
    "/build/"
    "/build-gcc/"
    "/cmake-build-debug/"
    "/cmake-build-release/"
)

list(FILTER ISADO_C_SOURCES
    EXCLUDE REGEX ".*${dir}.*"
)

list(FILTER ISADO_CPP_SOURCES
    EXCLUDE REGEX ".*${dir}.*"
)

endforeach()

# =====================================================
# Remove tests
# =====================================================

list(FILTER ISADO_C_SOURCES
    EXCLUDE REGEX ".*/tests/.*"
)

list(FILTER ISADO_CPP_SOURCES
    EXCLUDE REGEX ".*/tests/.*"
)

# =====================================================
# Executable
# =====================================================

add_executable(isado
    ${ISADO_C_SOURCES}
    ${ISADO_CPP_SOURCES}
)

# =====================================================
# Include directories
# =====================================================

target_include_directories(isado PRIVATE

    .

    boot
    core
    kernel
    logger
    shell

    system
    system/ai
    system/internet
    system/phone

    process

    gui
    ui
    launcher
    wm

    graphics
    filesystem
    sdk
    apps
    assets

    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
)

# =====================================================
# Link directories
# =====================================================

target_link_directories(isado PRIVATE

    ${SDL2_LIBRARY_DIRS}
    ${SDL2IMAGE_LIBRARY_DIRS}
    ${SDL2TTF_LIBRARY_DIRS}

)

# =====================================================
# Libraries
# =====================================================

target_link_libraries(isado PRIVATE

    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}

)

# =====================================================
# Compiler options
# =====================================================

if(MSVC)

    target_compile_options(isado PRIVATE
        /W4
    )

else()

    target_compile_options(isado PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

endif()

# =====================================================
# Output directory
# =====================================================

set_target_properties(isado PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"

)

# =====================================================
# Messages
# =====================================================

message(STATUS "---------------------------------------")
message(STATUS "ISADO OS Build")
message(STATUS "C Sources   : ${ISADO_C_SOURCES}")
message(STATUS "C++ Sources : ${ISADO_CPP_SOURCES}")
message(STATUS "SDL2        : ${SDL2_VERSION}")
message(STATUS "---------------------------------------")