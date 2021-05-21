cmake_minimum_required(VERSION 3.19)

project(learn-mpi)

find_package(MPI REQUIRED)

add_executable(hello src/hello.cpp)
add_executable(pi src/pi.cpp)

include_directories(${MPI_C_INCLUDE_PATH})

target_link_libraries(hello ${MPI_C_LIBRARIES})
target_link_libraries(pi ${MPI_C_LIBRARIES})