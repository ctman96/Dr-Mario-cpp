//
// Created by Cody on 6/8/2018.
//

#include "Block.h"

int Block::getX() const {
    return x;
}

void Block::setX(int x) {
    Block::x = x;
}

int Block::getY() const {
    return y;
}

void Block::setY(int y) {
    Block::y = y;
}

Color Block::getColor() const {
    return color;
}
