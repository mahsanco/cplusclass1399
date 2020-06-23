cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++17")
project(sajjad)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(CMake src/main.cpp)





