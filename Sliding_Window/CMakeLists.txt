cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#set Project
project(SlidingWindow VERSION 1.10)

# Library
add_library(${PRJECT_NAME}_lib STATIC src/fixed_window.cpp
                                      src/variable_window.cpp)

# Executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PRJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME} PUBLIC include)
