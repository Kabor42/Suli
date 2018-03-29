cmake_minimum_required(VERSION 3.9)
project(ConsoleRPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(ConsoleRPG main.cpp functions.hpp functions.cpp Game.cpp Game.hpp Character.cpp Character.hpp item.cpp item.hpp inventory.cpp inventory.hpp)