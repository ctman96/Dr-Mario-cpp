//! Represents a sprite on a spritesheet for rendering
/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#ifndef DRMARIO_SPRITE_H
#define DRMARIO_SPRITE_H


#include <SDL_render.h>

class Sprite {
public:
    Sprite(SDL_Texture *spritesheet, SDL_Rect *clip, SDL_Renderer *renderer);

    virtual ~Sprite();

    void setRotation(int rotation);

    virtual void render(int x, int y);

protected:
    //! The loaded texture of the spritesheet
    SDL_Texture* spritesheet;

    //! The rectangle representing the location of the sprite on the spritesheet
    SDL_Rect* clip;


    SDL_Renderer* renderer;

    //! The angle to rotate the sprite
    int rotation = 0;
};


#endif //DRMARIO_SPRITE_H
