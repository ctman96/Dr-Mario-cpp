//
// Created by Cody on 13/06/2018.
//

#ifndef DRMARIO_SINGLEPLAYERSTATE_H
#define DRMARIO_SINGLEPLAYERSTATE_H

#include "GameState.h"
#include "../GameUtils.h"

class SinglePlayerState : public GameState {
public:
    SinglePlayerState(int level, Speed speed, Music music);

    void init(GameEngine *game) override;

    void terminate() override;

    void handle(GameEngine *game) override;
    void update(GameEngine *game) override;
    void draw(GameEngine *game) override;

private:
    int level;
    Speed speed;
    Music music;

    SDL_Texture* spritesheet;
    SDL_Rect sprites[1];

    int score;
    int topscore;

    //TODO list of all capsules/blocks, viruses, active capsule, next capsule

};


#endif //DRMARIO_SINGLEPLAYERSTATE_H
