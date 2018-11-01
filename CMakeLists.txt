cmake_minimum_required(VERSION 3.12)
project(LBFL)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ThirdParty/Catch2)

set(WITH_GFLAGS FALSE)
add_subdirectory(ThirdParty/glog)

aux_source_directory(Source SRC_LIST)
add_executable(LBFL ${SRC_LIST})
target_include_directories(LBFL PUBLIC Include)
target_link_libraries(LBFL glog::glog)