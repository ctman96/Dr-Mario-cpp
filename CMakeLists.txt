cmake_minimum_required(VERSION 3.10)
project(DrMario)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})
#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIR})

add_executable(DrMario main.cpp Block.cpp Block.h Capsule.cpp Capsule.h Virus.cpp Virus.h Constants.h Engine/GameEngine.cpp Engine/GameEngine.h Engine/States/GameState.h Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h)
#target_link_libraries(DrMario ${SDL2_LIBRARY})