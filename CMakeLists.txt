cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(ProLog)

#Bring the headers into the project
include_directories(include)

#Add sources:
file(GLOB SOURCES "src/*.cpp")

file(MAKE_DIRECTORY /usr/lib/prolog)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY /usr/lib/prolog)

add_library(prolog STATIC ${SOURCES})