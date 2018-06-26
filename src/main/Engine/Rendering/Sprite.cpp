/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#include "Sprite.h"
#include "RenderUtils.h"

using namespace RenderUtils;

Sprite::Sprite(SDL_Texture *spritesheet, SDL_Rect *clip, SDL_Renderer *renderer) : spritesheet(spritesheet), clip(clip),
                                                                                   renderer(renderer) {}

Sprite::~Sprite() {

}

void Sprite::setRotation(int rotation) {
    Sprite::rotation = rotation;
}

void Sprite::render(int x, int y) {
    renderSpriteFromSheet(renderer, x, y, spritesheet, clip, rotation);
}
