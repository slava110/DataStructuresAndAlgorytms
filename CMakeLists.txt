cmake_minimum_required(VERSION 3.21)
project(DSAA)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)

enable_testing()

#add_executable(task0 task0/main.cpp)

add_executable(Main main.cpp)

add_executable(task0 task0/main.cpp)
add_executable(test0 task0/test.cpp)

add_executable(task1 task1/main.cpp)
add_executable(test1 task1/test.cpp)

add_executable(task2 task2/main.cpp)
add_executable(test2 task2/test.cpp)

add_executable(task3 task3/main.cpp)
add_executable(test3 task3/test.cpp)

add_executable(task4 task4/main.cpp)
add_executable(test4 task4/test.cpp)

add_test(Test0 test0)
add_test(Test1 test1)
add_test(Test2 test2)
add_test(Test3 test3)
add_test(Test4 test4)