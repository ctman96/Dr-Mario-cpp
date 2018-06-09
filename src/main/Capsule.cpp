//
// Created by Cody on 6/8/2018.
//

#include "Capsule.h"

const Block &Capsule::getB1() const {
    return b1;
}

const Block &Capsule::getB2() const {
    return b2;
}

int Capsule::getRotation() const {
    return rotation;
}

void Capsule::setRotation(int rotation) {
    Capsule::rotation = rotation;
}
