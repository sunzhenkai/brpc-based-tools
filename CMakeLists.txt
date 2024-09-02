cmake_minimum_required(VERSION 3.21)
project(brpc-based-tools C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CPP_FLAGS} -O2 -fPIC -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(unofficial-brpc CONFIG REQUIRED)

set(THIRD_PARTIES
        unofficial::brpc::brpc-static
        protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite
        gflags::gflags fmt::fmt spdlog::spdlog glog::glog)

include_directories(src)
file(GLOB_RECURSE COMMON_SRC src/utils/**.cpp)
file(GLOB_RECURSE PRESS_SRC src/press/**.cpp tools/press/*.cpp)

add_executable(press ${PRESS_SRC} ${COMMON_SRC})
target_link_libraries(press ${THIRD_PARTIES})