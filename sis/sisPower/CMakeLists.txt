
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(sisPower)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/source")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/source/include")

include_directories(${INCLUDE_DIR})
add_library(${PROJECT_NAME}
	${SOURCE_DIR}/${PROJECT_NAME}.cpp
)
