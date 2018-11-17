add_library(LBFL LBFL.cpp)
target_include_directories(LBFL PUBLIC .)
target_link_libraries(LBFL glog::glog)