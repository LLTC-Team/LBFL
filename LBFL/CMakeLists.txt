project(LBFL)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

add_library(LBFL LBFL.cpp)
target_include_directories(LBFL PUBLIC .)
target_link_libraries(LBFL glog::glog)