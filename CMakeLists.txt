cmake_minimum_required(VERSION 3.4)
project(cpp_ssdp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lib/client.cpp lib/client.h lib/udp_listener.cpp lib/udp_listener.h)
add_executable(cpp_ssdp ${SOURCE_FILES})