cmake_minimum_required(VERSION 3.28)

project(c_env)

#set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(tests/include)

file(GLOB INCLUDES
        include/*.h
        tests/include/*.h
)

file(GLOB SOURCES
        src/*.cpp
        tests/src/*.cpp
        main.cpp
)

add_executable(c_env ${SOURCES}
        ${INCLUDES})
