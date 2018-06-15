//
// Created by Cody on 6/10/2018.
//

#ifndef DRMARIO_OPTIONSSTATE_H
#define DRMARIO_OPTIONSSTATE_H

#include "GameState.h"
#include "../../GameUtils.h"

class OptionsState : public GameState {
public:
    explicit OptionsState(bool twoplayer);

    void init(GameEngine *game) override;

    void terminate() override;

    void handle(GameEngine *game) override;
    void update(GameEngine *game) override;
    void draw(GameEngine *game) override;

private:
    bool twoplayer;

    Selection selection;
    int level1 = 0;
    int level2 = 0;
    Speed speed1 = Speed::med;
    Speed speed2 = Speed::med;
    Music music = Music::fever;

    SDL_Texture* spritesheet;
    SDL_Rect sprites[37];

    void selectionDown();
    void selectionUp();

    void incLevel(int& level);
    void decLevel(int& level);

    void incSpeed(Speed& speed);
    void decSpeed(Speed& speed);

    void incMusic();
    void decMusic();

    void loadSprites();

    void renderNum(SDL_Renderer* renderer, int level, int x, int y);
};


#endif //DRMARIO_OPTIONSSTATE_H
