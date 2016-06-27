cmake_minimum_required(VERSION 3.5)
project(Hashtable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Hashtable.cpp Hashtable.h LinkedList.cpp LinkedList.h)
add_executable(Hashtable ${SOURCE_FILES})