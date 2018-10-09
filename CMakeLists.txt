project(rational LANGUAGES CXX)

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CMAKE_BUILD_TYPE DEBUG)

set(SRC
    crational.cpp
    tests.cpp)

enable_testing()

add_executable(tst_${PROJECT_NAME} ${SRC})

add_test(${PROJECT_NAME} tst_${PROJECT_NAME})
