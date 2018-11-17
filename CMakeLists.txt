cmake_minimum_required(VERSION 3.12)
project(LBFL)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ThirdParty/Catch2)

set(WITH_GFLAGS FALSE)
add_subdirectory(ThirdParty/glog)

add_subdirectory(LBFL)