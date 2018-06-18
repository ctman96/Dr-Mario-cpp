//
// Created by Cody on 6/8/2018.
//

#include "Capsule.h"

int Capsule::getRotation() const {
    return rotation;
}

void Capsule::setRotation(int rotation) {
    Capsule::rotation = rotation;
}

void Capsule::draw(SDL_Renderer *renderer) const {
    //TODO
}
