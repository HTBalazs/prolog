cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -O3 -fPIC")
project(ProLog)

#Bring the headers into the project
include_directories(include)

#Add sources and includes:
file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

# Define library and include directories
set(STATIC_LIB_DIR ~/local/lib/prolog)
set(INCLUDE_DIR ~/local/include/prolog)

# set archive output to <project_directory>/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib/)

# generate libprolog.a file
add_library(prolog STATIC ${SOURCES})

# install lib and include directories
install(TARGETS prolog DESTINATION ${STATIC_LIB_DIR})
install(FILES ${INCLUDES} DESTINATION ${INCLUDE_DIR})
