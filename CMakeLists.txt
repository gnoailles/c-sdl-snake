cmake_minimum_required(VERSION 3.8)
project(snake_sdl)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
set(CMAKE_CXX_STANDARD 11)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES
        const.h
        graphics.c
        graphics.h
        main.c
        Vector.c
        Vector.h
        perlin.c
        perlin.h Snake.c Snake.h SnakePart.c SnakePart.h)

add_executable(snake_sdl ${SOURCE_FILES})
target_link_libraries(snake_sdl ${SDL2_LIBRARIES} m)