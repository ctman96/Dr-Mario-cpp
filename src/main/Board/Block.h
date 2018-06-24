//! Separated piece of a Capsule
/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#ifndef DRMARIO_BLOCK_H
#define DRMARIO_BLOCK_H

#include "DrawableObject.h"
#include "../enums.h"

class Block : public DrawableObject{
public:
    Block(int x, int y, Color color);

    //! The colour of the block
    Color color{};
private:
};


#endif //DRMARIO_BLOCK_H
