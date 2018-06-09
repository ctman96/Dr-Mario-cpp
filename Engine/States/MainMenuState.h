//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_MAINMENUSTATE_H
#define DRMARIO_MAINMENUSTATE_H


#include "GameState.h"

class MainMenuState  : public GameState{
public:
    void init() override;

    void terminate() override;

    void handle(GameEngine *game) override;
    void update(GameEngine *game) override;
    void draw(GameEngine *game) override;


};


#endif //DRMARIO_MAINMENUSTATE_H
