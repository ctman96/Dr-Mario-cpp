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
    //! Returns the rotation value
    Rotation getRotation() const;

    //! Sets the rotation value
    void setRotation(Rotation rotation);

private:
    //! The colour of the first half of the capsule
    Color c1{};
    //! The colour of the second half of the capsule
    Color c2{};
    //! The rotation of the capsule
    Rotation rotation = Rotation::l;
};


#endif //DRMARIO_CAPSULE_H
