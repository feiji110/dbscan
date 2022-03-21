cmake_minimum_required(VERSION 3.16)
project(dbscan)

set(CMAKE_CXX_STANDARD 11)

#add_executable(dbscan include/dbscan.h include/nanoflann.hpp dbscan.cpp original.cpp)
add_executable(dbscan include/dbscan.h include/nanoflann.hpp  revised.cpp dbscan.cpp)
