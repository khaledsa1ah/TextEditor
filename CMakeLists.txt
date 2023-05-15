cmake_minimum_required(VERSION 3.21)
project(Assignment_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Text_editor "Text_editor.cpp")

add_library(Text_library "Text editor library.cpp" "Text editor library.h")

add_executable(Assignment_4 main.cpp)

