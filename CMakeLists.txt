cmake_minimum_required(VERSION 3.4)
project(cpp_ssdp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Boost COMPONENTS system REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

set(SOURCE_FILES main.cpp lib/client.cpp lib/client.h lib/udp_listener.cpp lib/udp_listener.h lib/parser.cpp lib/parser.h)
add_executable(cpp_ssdp ${SOURCE_FILES})
target_link_libraries(cpp_ssdp ${Boost_LIBRARIES})