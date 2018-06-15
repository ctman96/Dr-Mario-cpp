//
// Created by Cody on 13/06/2018.
//

#ifndef DRMARIO_SINGLEPLAYERSTATE_H
#define DRMARIO_SINGLEPLAYERSTATE_H

#include "GameState.h"
#include "../../GameUtils.h"
#include "../../Capsule.h"
#include "../../Virus.h"
#include <list>

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

    void loadSprites();

    int score;
    int topscore;

    std::list<Virus> viruses;
    std::list<Block> listOfBlocks;
    std::list<Capsule> listOfCapsules;
    Capsule* activeCapsule;
    Capsule nextCapsule;

};


#endif //DRMARIO_SINGLEPLAYERSTATE_H
