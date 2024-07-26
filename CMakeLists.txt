cmake_minimum_required(VERSION 3.10.0)

project(easy_log)

include_directories(${PROJECT_SOURCE_DIR}/base)

include_directories(${PROJECT_SOURCE_DIR}/log)

add_executable(buffer_test test/buffer_test.cpp)