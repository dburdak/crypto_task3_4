cmake_minimum_required(VERSION 3.14)
project(hash_project VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(MSVC)
    add_compile_options(/O2 /Ot /GT)
else()
    add_compile_options(-O3 -march=native -flto)
endif()

find_package(GTest REQUIRED)
add_library(hash_lib hash_func.cpp hash_func.h)

add_executable(hash_project main.cpp)
target_link_libraries(hash_project PRIVATE hash_lib)

add_executable(hash_tests tests/tests.cpp)
target_link_libraries(hash_tests PRIVATE hash_lib GTest::gtest GTest::gtest_main)