//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_GAMESTATE_H
#define DRMARIO_GAMESTATE_H

#include "../GameEngine.h"

class GameState {
public:
    virtual void init(GameEngine *game) = 0;
    virtual void terminate() = 0;

    virtual void handle(GameEngine *game) = 0;
    virtual void update(GameEngine *game) = 0;
    virtual void draw(GameEngine *game) = 0;

    void changeState(GameEngine *game, GameState *state){
        game->changeState(state);
    }

    virtual ~GameState() = default;
};


#endif //DRMARIO_GAMESTATE_H
