//! Capsule game object
/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#ifndef DRMARIO_CAPSULE_H
#define DRMARIO_CAPSULE_H

#include "DrawableObject.h"
#include "../enums.h"

class Capsule : public DrawableObject{
public:
    //! The colour of the first half of the capsule
    Color color1{};
    //! The colour of the second half of the capsule
    Color color2{};

    Capsule();

    Capsule(int x, int y, Color c1, Color c2);



    //! Returns the rotation value
    Rotation getRotation() const;

    //! Sets the rotation value
    void setRotation(Rotation rotation);

    //! Rotates the capsule clockwise
    void rotateCW();

    //! Rotates the capsule counter-clockwise
    void rotateCCW();

    //! Gets the x value of second half of the capsule
    int getX2() const;

    //! Gets the y value of second half of the capsule
    int getY2() const;

    void draw(GameRenderer* renderer, int x, int y) override;

    bool operator==(const DrawableObject& other) const override ;

private:
    //! The rotation of the capsule
    /*!
     * The value represents the relative position of 1st half of the capsule (x,y) to the second half (x2,y2)
     * ie.  l means x = x2 - 1, y = y2
     *      d means x = x2, y = y2 - 1
     *      ,etc.
     */
    Rotation rotation = Rotation::l;

    //! Sets the sprite based on colors
    void generateSprite();
};


#endif //DRMARIO_CAPSULE_H
