//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_MAINMENUSTATE_H
#define DRMARIO_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState  : public GameState{
public:
    void init(GameEngine *game) override;

    void terminate() override;

    void handle(GameEngine *game) override;
    void update(GameEngine *game) override;
    void draw(GameEngine *game) override;

private:
    SDL_Texture* spritesheet;
    SDL_Rect sprites[12];
    bool cursor = false;
    void renderSprite(SDL_Renderer* renderer, int x, int y, SDL_Rect* sprite);
};


#endif //DRMARIO_MAINMENUSTATE_H
