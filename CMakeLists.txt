cmake_minimum_required(VERSION 3.20)

project(stack_calc)

add_compile_options(-Wall -pedantic -Werror)
set(CMAKE_CXX_STANDARD 14)

include_directories(SafeInt/)
add_subdirectory(googletest)

add_executable(stack_calc)
add_executable(stack_calc_test)

target_sources(stack_calc PRIVATE
               main.cpp
               Actions.cpp
               Actions.h
               ConcreteActionCreator.h
               ConcreteActionCreator.cpp
               StackCalc.cpp
               StackCalc.h)

target_sources(stack_calc_test PRIVATE
               test.cpp
               Actions.cpp
               Actions.h
               ConcreteActionCreator.h
               ConcreteActionCreator.cpp
               StackCalc.cpp
               StackCalc.h)

target_link_libraries(stack_calc_test gtest gtest_main)