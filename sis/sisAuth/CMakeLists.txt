
cmake_minimum_required(VERSION 3.2)

project(sisAuth)

include_directories(${PROJECT_SOURCE_DIR}/source/include)
add_library(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/source/${PROJECT_NAME}.cpp)
