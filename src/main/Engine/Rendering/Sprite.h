//! Represents a sprite on a spritesheet for rendering
/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#ifndef DRMARIO_SPRITE_H
#define DRMARIO_SPRITE_H


#include <SDL_render.h>
#include "GameRenderer.h"

class Sprite {
public:
    Sprite();

    explicit Sprite(const SDL_Rect *clip);

    virtual ~Sprite();

    void setRotation(int rotation);

    virtual void render(GameRenderer* renderer, int x, int y);

protected:

    //! The rectangle representing the location of the sprite on the spritesheet
    const SDL_Rect* clip;

    //! The angle to rotate the sprite
    int rotation = 0;
};


#endif //DRMARIO_SPRITE_H
