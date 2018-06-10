//
// Created by Cody on 6/10/2018.
//

#ifndef DRMARIO_OPTIONSSTATE_H
#define DRMARIO_OPTIONSSTATE_H

#include "GameState.h"

enum class selection {level, speed, music};
enum class speed {low, med, hi};
enum class music {fever, chill, off};

class OptionsState : public GameState {
public:
    void init(GameEngine *game) override;

    void terminate() override;

    void handle(GameEngine *game) override;
    void update(GameEngine *game) override;
    void draw(GameEngine *game) override;

private:
    int level;
    speed speed;
    music music;

    SDL_Texture* spritesheet;
    SDL_Rect sprites[1]; //TODO change
};


#endif //DRMARIO_OPTIONSSTATE_H
