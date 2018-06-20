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
    //! Returns the colour of the block
    Color getColor() const;

    //! Renders the block
    //! \param renderer the Renderer to be used for rendering
    void draw(SDL_Renderer *renderer) const override;

private:
    //! The colour of the block
    Color color{};
};


#endif //DRMARIO_BLOCK_H
