
cmake_minimum_required(VERSION 2.6)
project(cpp_concurrency_in_action)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(Listing1.1 ../ch01/Listing1.1.cpp)
target_link_libraries(Listing1.1 pthread)

add_executable(Listing2.1 ../ch02/Listing2.1.cpp)
target_link_libraries(Listing2.1 pthread)

add_executable(Listing2.2 ../ch02/Listing2.2.cpp)
target_link_libraries(Listing2.2 pthread)

add_executable(Listing2.3 ../ch02/Listing2.3.cpp)
target_link_libraries(Listing2.3 pthread)

add_executable(Listing2.4 ../ch02/Listing2.4.cpp)
target_link_libraries(Listing2.4 pthread)

add_executable(Listing2.5 ../ch02/Listing2.5.cpp)
target_link_libraries(Listing2.5 pthread)

add_executable(Listing2.6 ../ch02/Listing2.6.cpp)
target_link_libraries(Listing2.6 pthread)

add_executable(Listing2.7 ../ch02/Listing2.7.cpp)
target_link_libraries(Listing2.7 pthread)