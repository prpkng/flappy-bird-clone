cmake_minimum_required(VERSION 4.4)
enable_testing()

project(FlappyBirdClone)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

add_subdirectory(Engine/)
add_subdirectory(Game/)
add_subdirectory(tests/)
