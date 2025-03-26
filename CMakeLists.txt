cmake_minimum_required(VERSION 3.24)
project(cs317)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

set(CMAKE_CXX_STANDARD 17)

add_executable(cs317 main.cpp)

target_link_libraries(cs317 ${MPI_LIBRARIES})
