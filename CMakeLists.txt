cmake_minimum_required(VERSION 3.16)
project(dbscan)

set(CMAKE_CXX_STANDARD 11)

#add_executable(dbscan include/dbscan.h  dbscan.cpp original.cpp)
add_executable(dbscan include/dbscan.h   revised.cpp dbscan.cpp)
