/*!
 * @author: Cody Newman
 *
 * Created on: 26/06/2018
 */

#include <iostream>
#include "GameRenderer.h"

GameRenderer::GameRenderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::string msg = "Renderer could not be created. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }
}

GameRenderer::~GameRenderer() {
    SDL_DestroyRenderer(renderer);
}

SDL_Texture *GameRenderer::getSpritesheet() const {
    return spritesheet;
}

void GameRenderer::setSpritesheet(SDL_Texture *spritesheet) {
    GameRenderer::spritesheet = spritesheet;
}

SDL_Renderer *GameRenderer::getRenderer() const {
    return renderer;
}
