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

    //! Constructor, sets position and color
    Virus(int x, int y, Color color);

    //! The colour of the virus
    Color color{};
};


#endif //DRMARIO_VIRUS_H
