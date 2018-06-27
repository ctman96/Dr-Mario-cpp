/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include "Virus.h"
#include "../Resources/spritesheets.h"
#include "../Engine/Rendering/AnimatedSprite.h"

Virus::Virus(int x, int y, Color color) : DrawableObject(x, y), color(color) {
    generateSprite();
}

void Virus::generateSprite() {
    // TODO set speed
    if (sprite != nullptr){
        delete(sprite);
    }
    switch(color){
        case Color::red:
            sprite = new AnimatedSprite(std::list<const SDL_Rect*>{&spr_game[48], &spr_game[49]}, 1, true);
            break;
        case Color::blue:
            sprite = new AnimatedSprite(std::list<const SDL_Rect*>{&spr_game[44], &spr_game[45]}, 1, true);
            break;
        case Color::yellow:
            sprite = new AnimatedSprite(std::list<const SDL_Rect*>{&spr_game[46], &spr_game[47]}, 1, true);
            break;
    }
}
