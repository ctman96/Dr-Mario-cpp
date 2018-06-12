//
// Created by Cody on 11/06/2018.
//

#include "RenderUtils.h"
#include "../Constants.h"

void
RenderUtils::renderSpriteFromSheet(SDL_Renderer *renderer, int x, int y, SDL_Texture *spritesheet, SDL_Rect *sprite) {
    if (sprite == nullptr){
        return;
    }
    SDL_Rect render = {x*SCALING,y*SCALING,sprite->w*SCALING,sprite->h*SCALING};
    SDL_RenderCopy(renderer, spritesheet, sprite, &render);
}
