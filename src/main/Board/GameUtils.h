//! Provides utility functions for the game board
/*!
 * Provides a namespace containing utility functions
 * to help with generating and updating game pieces
 *
 * @author: Cody Newman
 *
 * Created on: 13/06/2018
 */

#ifndef DRMARIO_GAMEUTILS_H
#define DRMARIO_GAMEUTILS_H

#include <set>
#include "Virus.h"
#include "Capsule.h"


namespace GameUtils {
    //! Generates the viruses set based on the board level
    std::set<Virus> generateLevel(int level);

    //! Updates the blocks set
    void updateBlocks(const std::set<Virus>& viruses, std::set<DrawableObject*>& blocks);

    //! Clears any rows of matching blocks
    void clearMatches(std::set<Virus>& viruses, std::set<DrawableObject*>& blocks);

    //! Updates the activeCapsule
    void updateActive(const std::set<Virus>& viruses, const std::set<DrawableObject*>& blocks, Capsule& activeCapsule);

};


#endif //DRMARIO_GAMEUTILS_H
