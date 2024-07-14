cmake_minimum_required(VERSION 3.0)
project(Cpp-Lox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(cpp-lox ${SOURCES})
