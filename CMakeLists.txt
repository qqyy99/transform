cmake_minimum_required (VERSION 2.8)
project(eigen_transform)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

include_directories("/usr/include/eigen3")
add_executable(${PROJECT_NAME} transform.cpp)