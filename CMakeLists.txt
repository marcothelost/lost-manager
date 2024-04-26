# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "lmgr")

# Project Name
project(${PROJECT_NAME})

# Executable
add_executable(
  lmgr
  ${CMAKE_SOURCE_DIR}/src/Main.c
  ${CMAKE_SOURCE_DIR}/src/Todo.c
)
target_include_directories(lmgr PUBLIC ${CMAKE_SOURCE_DIR}/include)
