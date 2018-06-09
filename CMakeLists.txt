cmake_minimum_required(VERSION 3.10)
project(DrMario)

set(CMAKE_CXX_STANDARD 11)

add_executable(DrMario main.cpp Block.cpp Block.h Capsule.cpp Capsule.h Virus.cpp Virus.h Constants.h Engine/GameEngine.cpp Engine/GameEngine.h Engine/States/GameState.h Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h)