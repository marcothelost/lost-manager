# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "lmgr")

# Project Name
project(${PROJECT_NAME})

# Executable
add_executable(
  lmgr
  src/Main.c
)
