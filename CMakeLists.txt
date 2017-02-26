file(GLOB SOURCES src/*.cpp)
cmake_minimum_required (VERSION 3.7.2)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wc++11-extensions -std=c++11")
project (conwayCPP)
add_executable(conwayCPP ${SOURCES})
set(SOURCE_FILES src/*)

enable_testing()
add_test(test1 test)
