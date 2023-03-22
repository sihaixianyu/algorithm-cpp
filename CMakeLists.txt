cmake_minimum_required(VERSION 3.0.0)

project(algorithm-c C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

set(SOURCES src/main.c)

add_executable(${PROJECT_NAME} ${SOURCES})
