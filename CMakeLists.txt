cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0037 OLD)

set(LIB_IRRLITCH src/main.cpp)

add_custom_target(install DEPENDS ${LIB_IRRLITCH})

add_executable(cpp_indie_studio src/main.cpp)