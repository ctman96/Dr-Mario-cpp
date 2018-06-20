//! Virus game object
/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#ifndef DRMARIO_VIRUS_H
#define DRMARIO_VIRUS_H

#include "DrawableObject.h"
#include "../enums.h"

class Virus : public DrawableObject {
public:
    //! Renders the capsule
    //! \param renderer the Renderer to be used
    void draw(SDL_Renderer *renderer) const override;
private:
    //! The colour of the virus
    Color color{};
};


#endif //DRMARIO_VIRUS_H
