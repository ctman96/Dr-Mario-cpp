//! Wrapper class for SDL_renderer, which also keeps track of
/*!
 *
 * @author: Cody Newman
 *
 * Created on: 26/06/2018
 */

#ifndef DRMARIO_GAMERENDERER_H
#define DRMARIO_GAMERENDERER_H


#include <SDL_render.h>

class GameRenderer {
public:
    explicit GameRenderer(SDL_Window* window);

    virtual ~GameRenderer();

    SDL_Texture *getSpritesheet() const;

    void setSpritesheet(SDL_Texture *spritesheet);

    SDL_Renderer *getRenderer() const;

private:
    SDL_Renderer* renderer;

    SDL_Texture* spritesheet;
};


#endif //DRMARIO_GAMERENDERER_H
