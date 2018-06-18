//
// Created by Cody on 6/17/2018.
//

#ifndef DRMARIO_BOARD_H
#define DRMARIO_BOARD_H


#include <set>
#include <memory>
#include <SDL_render.h>
#include "Virus.h"
#include "Block.h"
#include "Capsule.h"
#include "../Constants.h"
#include "../GameUtils.h"

enum class boardState {};

class Board {
public:
    void init(int level);
    void clear();
    void update();
    void draw(SDL_Renderer* renderer);
private:
    std::set<std::unique_ptr<Virus>> viruses;
    std::set<std::unique_ptr<DrawableObject>> blocks;
    //std::set<std::unique_ptr<Capsule>> capsules;
    Capsule activeCapsule;
    Capsule nextCapsule;
    Cell board[BOARD_WIDTH_CELLS][BOARD_HEIGHT_CELLS]{};
};


#endif //DRMARIO_BOARD_H
