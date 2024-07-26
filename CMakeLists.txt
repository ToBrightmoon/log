cmake_minimum_required(VERSION 3.10.0)

project(easy_log)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/base/include)

include_directories(${PROJECT_SOURCE_DIR}/log/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/base/src)

include_directories(${PROJECT_SOURCE_DIR}/log/src)

add_executable(buffer_test test/buffer_test.cpp)