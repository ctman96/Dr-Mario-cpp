//
// Created by Cody on 11/06/2018.
//

#ifndef DRMARIO_RENDERUTILS_H
#define DRMARIO_RENDERUTILS_H


#include <SDL_image.h>

namespace RenderUtils {
    void renderSpriteFromSheet(SDL_Renderer* renderer, int x, int y, SDL_Texture* spritesheet, SDL_Rect* sprite);
};


#endif //DRMARIO_RENDERUTILS_H
