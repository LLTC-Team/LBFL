project(LBFLTest)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

add_executable(LBFLTest LBFLTest.cpp)
target_link_libraries(LBFLTest Catch2::Catch2 LBFL)