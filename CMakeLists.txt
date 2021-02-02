cmake_minimum_required(VERSION 3.1)
project(otus1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(${CMAKE_CXX_STANDARD})

add_executable( testingString testingstring.cpp testingbase.cpp)


target_link_libraries(testingString stdc++fs) 