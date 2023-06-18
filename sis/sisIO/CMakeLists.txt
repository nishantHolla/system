
cmake_minimum_required(VERSION 3.2)

project(sisIO)

include_directories(${PROJECT_SOURCE_DIR}/source/include)
add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/source/sisIO.cpp)
