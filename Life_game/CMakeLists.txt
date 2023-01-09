cmake_minimum_required(VERSION 3.5)

project(Life_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Life_game main.cpp grid.cpp grid.hpp)
