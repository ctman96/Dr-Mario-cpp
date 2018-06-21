/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include "Capsule.h"

Rotation Capsule::getRotation() const {
    return rotation;
}

void Capsule::setRotation(Rotation rotation) {
    Capsule::rotation = rotation;
}
