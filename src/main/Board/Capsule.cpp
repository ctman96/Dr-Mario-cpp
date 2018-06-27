/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include "Capsule.h"
#include "../Resources/spritesheets.h"

Capsule::Capsule(int x, int y, Color c1, Color c2) : DrawableObject(x, y), color1(c1), color2(c2) {
    rotation = Rotation::l;
    generateSprite();
}

void Capsule::generateSprite() {
    if (sprite != nullptr){
        delete(sprite);
    }
    int spr = 0;
    switch(color1){
        case Color::red:
            switch(color2){
                case Color::red:
                    spr = 59;
                    break;
                case Color::blue:
                    spr = 60;
                    break;
                case Color::yellow:
                    spr = 61;
                    break;
            }
            break;
        case Color::blue:
            switch(color2){
                case Color::red:
                    spr = 58;
                    break;
                case Color::blue:
                    spr = 56;
                    break;
                case Color::yellow:
                    spr = 57;
                    break;
            }
            break;
        case Color::yellow:
            switch(color2){
                case Color::red:
                    spr = 55;
                    break;
                case Color::blue:
                    spr = 54;
                    break;
                case Color::yellow:
                    spr = 53;
                    break;
            }
            break;
    }
    sprite = new Sprite(&spr_game[spr]);
}

Rotation Capsule::getRotation() const {
    return rotation;
}

void Capsule::setRotation(Rotation rotation) {
    Capsule::rotation = rotation;
}

Capsule::Capsule() {
    x = 3;
    y = 15;
    color1 = Color::yellow;
    color2 = Color::yellow;
}

/*!
 * Rotates the capsule clockwise, adjusting the x,y, and rotation values
 */
void Capsule::rotateCW() {
    // For the following notations, 1 = (x,y), 2 = position of second half, 0 is empty
    switch(rotation){
        /*
         * 0 0      1 0
         * 1 2 ->   2 0
         */
        case Rotation::l:
            rotation = Rotation::u;
            y++;
            break;
        /*
         * 1 0    0 0
         * 2 0 -> 2 1
         */
        case Rotation::u:
            rotation = Rotation::r;
            x++;
            y--;
            break;
        /*
         * 0 0      2 0
         * 2 1 ->   1 0
         */
        case Rotation::r:
            rotation = Rotation::d;
            x--;
            break;
        /*
         * 2 0    0 0
         * 1 0 -> 1 2
         */
        case Rotation::d:
            rotation = Rotation::l;
            break;
    }
}

/*!
 * Rotates the capsule counter clockwise, adjusting the x,y, and rotation values
 */
void Capsule::rotateCCW() {
    switch(rotation){
        /*
         * 0 0      2 0
         * 1 2 ->   1 0
         */
        case Rotation::l:
            rotation = Rotation::d;
            break;
        /*
         * 2 0    0 0
         * 1 0 -> 2 1
         */
        case Rotation::d:
            rotation = Rotation::r;
            x++;
            break;
        /*
         * 0 0      1 0
         * 2 1 ->   2 0
         */
        case Rotation::r:
            rotation = Rotation::u;
            x--;
            y++;
            break;
        /*
         * 1 0    0 0
         * 2 0 -> 1 2
         */
        case Rotation::u:
            rotation = Rotation::l;
            y--;
            break;
    }
}

int Capsule::getX2() const {
    switch(rotation){
        /*
         * 1 2
         */
        case Rotation::l:
            return x+1;
        /*
         * 1
         * 2
         */
        case Rotation::u:
            return x;
        /*
         * 2 1
         */
        case Rotation::r:
            return x-1;
        /*
         * 2
         * 1
         */
        case Rotation::d:
            return x;
    }
    return -1; //Prevents compiler warning "control reaches end of non-void function", but is otherwise unnecessary
}

int Capsule::getY2() const {
    switch(rotation){
        /*
         * 1 2
         */
        case Rotation::l:
            return y;
        /*
         * 1
         * 2
         */
        case Rotation::u:
            return y-1;
        /*
         * 2 1
         */
        case Rotation::r:
            return y;
        /*
         * 2
         * 1
         */
        case Rotation::d:
            return y+1;
    }
    return -1; //Prevents compiler warning "control reaches end of non-void function", but is otherwise unnecessary
}

//! Updates the sprites rotation before drawing
void Capsule::draw(GameRenderer *renderer, int x, int y) {
    //TODO set sprite rotation properly (changing center point depending on rotation?)
    int angle = 0;
    switch(rotation){
        case Rotation::l:
            break;
        case Rotation::u:
            angle = 90;
            break;
        case Rotation::r:
            angle = 180;
            break;
        case Rotation::d:
            angle = 270;
            break;
    }
    sprite->setRotation(angle);
    DrawableObject::draw(renderer, x, y);
}

/*!
 * Compares both halves of the capsule to the other object
 * Checks if either half has the same posisiton as other
 * @param other the DrawableObject being compared to
 * @return true if x and y of either half of the Capsule match the x and y of other
 */
bool Capsule::operator==(const DrawableObject &other) const {
    bool b1 = DrawableObject::operator==(other);
    bool b2 = (getX2() == other.x && getY2() == other.y);

    return b1 || b2;
}
