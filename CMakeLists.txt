cmake_minimum_required(VERSION 3.12)
project(LBFL)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(Source SRC_LIST)
add_executable(LBFL ${SRC_LIST})
target_include_directories(LBFL PUBLIC Include)