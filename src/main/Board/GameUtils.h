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
#include "Block.h"


namespace GameUtils {
    template <class T>
    //! Checks if object t is contained in set
    bool setContains(const std::set<T>& set, T t);

    //! Generates the viruses set based on the board level
    bool generateVirus(std::set<Virus>& viruses, int level);

    //! Checks the colors of surrounding cells, such that it wont result in 3+ of the same color in a row
    bool checkColors(const std::set<Virus>& viruses, Virus& v);

    //! Generate a random capsule
    Capsule generateCapsule(int x, int y);

    //! Updates the blocks set
    void updateBlocks(const std::set<Virus>& viruses, std::set<Block>& blocks, std::set<Capsule>& capsules);

    //! Clears any rows of matching blocks
    void clearMatches(std::set<Virus>& viruses, std::set<Block>& blocks, std::set<Capsule>& capsules);

    //! Updates the activeCapsule
    void updateActive(const std::set<Virus>& viruses, const std::set<Block>& blocks, std::set<Capsule>& capsules,
                      Capsule& activeCapsule);

    //! Returns a color value for a given int;
    Color colorFromInt(int c);

    //! Checks if there will be a collision if activeCapsule moves with Move
    bool checkCollisions(const std::set<Virus>& viruses, const std::set<Block>& blocks, std::set<Capsule>& capsules,
                         Capsule& activeCapsule, Move move);

    //! Checks if the given x,y cooridnates are free of viruses or blocks
    bool checkFree(const std::set<Virus>& viruses, const std::set<Block>& blocks, std::set<Capsule>& capsules,
                   int x, int y);

};


#endif //DRMARIO_GAMEUTILS_H
