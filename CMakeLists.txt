
cmake_minimum_required(VERSION 3.10)

# set the project name
project(ASCII)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(includes)

file(GLOB SOURCES "src/*.cpp")

add_executable(ascii ${SOURCES})