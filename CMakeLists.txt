cmake_minimum_required(VERSION 3.10)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0037 OLD)   #Bypass install target restriction

add_custom_target(install DEPENDS ${LIB_IRRLITCH})

file(GLOB bomberman_src
        "src/*.cpp")

file(GLOB bomberman_inc
        "inc/*.hpp")

include_directories(${IRRLICHT_PATH_INCLUDE})

link_directories(${IRRLICHT_PATH_LIB})

add_executable(bomberman ${bomberman_src} ${bomberman_inc} inc/Ia.hpp src/Ia.cpp inc/Ia.hpp src/Ia.cpp inc/Ia.hpp src/Ia.cpp inc/Ia.hpp inc/IPlayer.hpp)

target_link_libraries(bomberman Irrlicht GL X11 Xxf86vm)

install (TARGETS bomberman DESTINATION .)

include (CPack)
