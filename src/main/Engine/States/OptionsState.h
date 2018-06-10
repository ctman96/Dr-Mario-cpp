//
// Created by Cody on 6/10/2018.
//

#ifndef DRMARIO_OPTIONSSTATE_H
#define DRMARIO_OPTIONSSTATE_H

#include "GameState.h"

enum class Selection {level, speed, music};
enum class Speed {low, med, hi};
enum class Music {fever, chill, off};

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
    int level;
    Speed speed;
    Music music;

    SDL_Texture* spritesheet;
    SDL_Rect sprites[37];

    void selectionDown();
    void selectionUp();

    void renderSprite(SDL_Renderer* renderer, int x, int y, SDL_Rect* sprite);

    void loadSprites();
};


#endif //DRMARIO_OPTIONSSTATE_H
