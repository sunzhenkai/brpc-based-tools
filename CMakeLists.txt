cmake_minimum_required(VERSION 3.21)
project(brpc-based-tools C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CPP_FLAGS} -O2 -fPIC -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

find_package(spdlog CONFIG REQUIRED)