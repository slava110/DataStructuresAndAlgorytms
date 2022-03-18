cmake_minimum_required(VERSION 3.21)
project(DSAA)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)

enable_testing()

#add_executable(task1 task1/main.cpp)

add_executable(task2 task2/main.cpp)
add_executable(test2 task2/test.cpp)

add_test(Test2 test2)

#add_executable(task3 task3/main.cpp)

