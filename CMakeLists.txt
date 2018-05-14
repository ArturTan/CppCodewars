project(codewars)
cmake_minimum_required(VERSION 2.8)
include_directories(..)
set(CMAKE_CXX_COMPILER /usr/bin/g++-7)

FILE(GLOB_RECURSE LibFiles "../CppCodewars/Poker/include/*.hpp")
add_custom_target(headers SOURCES ${LibFiles})
set(SOURCES main.cpp ../CppCodewars/Poker/src/Poker.cpp)
add_compile_options("-std=c++17")


add_executable(${PROJECT_NAME} ${SOURCES})


