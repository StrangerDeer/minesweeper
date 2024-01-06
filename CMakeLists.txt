cmake_minimum_required(VERSION 3.8)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
        Minesweeper.cpp
        Minesweeper.h
        Game.cpp
        Game.h
        Random.h)
add_executable(minesweeper ${SOURCE_FILES})