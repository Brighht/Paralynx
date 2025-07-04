cmake_minimum_required(VERSION 3.10)
project(Paralynx)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_library(paralynx
    src/TaskQueue.cpp
    src/Worker.cpp
    src/Profiler.cpp
)

add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main paralynx pthread)