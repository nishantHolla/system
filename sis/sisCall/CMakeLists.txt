
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(sisCall)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/source")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/source/include"
	)
set(LINK_DIR "${PROJECT_SOURCE_DIR}/source/library")

include_directories(
	${INCLUDE_DIR}
	${INCLUDE_DIR}/sisIO
	${INCLUDE_DIR}/sisAuth
	${INCLUDE_DIR}/sisPower
)
link_directories(${LINK_DIR})

link_libraries(sisIO sisAuth sisPower)
add_executable(${PROJECT_NAME}
	${SOURCE_DIR}/sisCall.cpp
	${SOURCE_DIR}/main.cpp
)
