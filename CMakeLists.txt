cmake_minimum_required(VERSION 3.13)

project(blaster)

set(CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

set(BLASTER_SRC 
    MainCli.cpp)

add_executable(blaster ${BLASTER_SRC})