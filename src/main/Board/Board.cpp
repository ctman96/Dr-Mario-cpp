//
// Created by Cody on 6/17/2018.
//

#include "Board.h"

using namespace std;

void Board::init(int level) {
    //TODO Generate Viruses, create starting capsule
}

void Board::clear() {
    viruses.clear();
    blocks.clear();
    //capsules.clear();
}

void Board::update() {
    //TODO create new activeCapsule if necessary
    auto itb = blocks.begin();
    for (int i = 0; i < blocks.size(); i++){
        //TODO update all block positions, checking for collisions
    }
    //TODO check lines, delete, add score
}

void Board::draw(SDL_Renderer* renderer, int x, int y) {
    auto itv = viruses.begin();
    for( int i = 0; i < viruses.size(); i++){
        itv->draw(renderer);
        next(itv);
    }
    auto itb = blocks.begin();
    for(int i = 0; i < blocks.size(); i++){
        (*itb)->draw(renderer);
        next(itb);
    }
    /*auto itc = capsules.begin();
    for(int i = 0; i < capsules.size(); i++){
        itc->get()->draw(renderer);
        next(itc);
    }*/
}
