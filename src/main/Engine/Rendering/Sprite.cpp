/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#include "Sprite.h"
#include "RenderUtils.h"

using namespace RenderUtils;

Sprite::Sprite() = default;

Sprite::Sprite(const SDL_Rect *clip) : clip(clip) {}

Sprite::~Sprite() {
    //TODO?
}

void Sprite::setRotation(int rotation) {
    Sprite::rotation = rotation;
}

void Sprite::render(GameRenderer* renderer, int x, int y) {
    renderSpriteFromSheet(renderer->getRenderer(), x, y, renderer->getSpritesheet(), clip, rotation);
}
