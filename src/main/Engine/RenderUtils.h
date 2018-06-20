//! Provides utility functions to do with rendering
/*!
 * Provides a namespace containing utility functions
 * to help with rendering various data
 *
 * @author: Cody Newman
 *
 * Created on: 11/06/2018
 */

#ifndef DRMARIO_RENDERUTILS_H
#define DRMARIO_RENDERUTILS_H


#include <SDL_image.h>

namespace RenderUtils {
    //! Renders a sprite from a spritesheet
    void renderSpriteFromSheet(SDL_Renderer* renderer, int x, int y, SDL_Texture* spritesheet, const SDL_Rect* sprite);
};


#endif //DRMARIO_RENDERUTILS_H
