//
// Created by Cody on 6/8/2018.
//

#include "GameEngine.h"
#include "States/GameState.h"

void GameEngine::init() {

}

void GameEngine::terminate() {

}

void GameEngine::changeState(GameState *state) {
    this->state = state;
}

void GameEngine::handle() {

}

void GameEngine::update() {
    state->update(this);
}

void GameEngine::draw() {
    state->draw(this);
}
