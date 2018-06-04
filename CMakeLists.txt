cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

add_executable(cpp_indie_studio
    inc/Core.hpp
    inc/Data.hpp
    inc/GenerateMap.hpp
    inc/IDisplay.hpp
    inc/IScene.hpp
    inc/ISound.hpp
    inc/Params.hpp
        inc/Position.hpp
    src/Core.cpp
    src/GenerateMap.cpp
    src/main.cpp
    src/Params.cpp
        )
