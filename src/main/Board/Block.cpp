/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include "Block.h"
#include "../Resources/spritesheets.h"

Block::Block(int x, int y, Color color) : DrawableObject(x, y), color(color) {
    generateSprite();
}

void Block::generateSprite() {
    if (sprite != nullptr){
        delete(sprite);
    }
    switch(color){
        case Color::red:
            sprite = new Sprite(&spr_game[52]);
            break;
        case Color::blue:
            sprite = new Sprite(&spr_game[51]);
            break;
        case Color::yellow:
            sprite = new Sprite(&spr_game[50]);
            break;
    }
}
