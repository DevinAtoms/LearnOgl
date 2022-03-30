cmake_minimum_required(VERSION 3.21)
project(OGL)

set(CMAKE_CXX_STANDARD 17)

add_executable(OGL src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/glad
        ${CMAKE_SOURCE_DIR}/include/KHR/
        ${CMAKE_SOURCE_DIR}/include/imgui)