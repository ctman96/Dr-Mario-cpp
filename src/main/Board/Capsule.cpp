/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include "Capsule.h"

Capsule::Capsule(int x, int y, Color c1, Color c2) : DrawableObject(x, y), c1(c1), c2(c2) {}

Rotation Capsule::getRotation() const {
    return rotation;
}

void Capsule::setRotation(Rotation rotation) {
    Capsule::rotation = rotation;
}

Capsule::Capsule() {
    x = 0;
    y = 0;
    c1 = Color::yellow;
    c2 = Color::yellow;
}
