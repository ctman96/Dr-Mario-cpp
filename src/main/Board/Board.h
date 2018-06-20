//! Represents a game board.
/*!
 *  The Board class represents the game board
 *  upon which gameplay takes place.
 *
 *  @author: Cody Newman
 *
 *  Created on: 17/06/2018
 */

#ifndef DRMARIO_BOARD_H
#define DRMARIO_BOARD_H


#include <set>
#include <memory>
#include <SDL_render.h>
#include "Virus.h"
#include "Block.h"
#include "Capsule.h"
#include "../Constants.h"
#include "../enums.h"

class Board {
public:
    //! Possible states of the board
    /*! The board can either be active, in which the
     * active capsule is moving, or updating, in which
     * the board updates falling pieces
     */
    enum class BoardState {active, updating};

    //! Initializes the board using the game level
    void init(int level);

    //! Clears all pieces from the game board
    void clear();

    //! Updates all game pieces
    void update();

    //! Renders all game pieces to the renderer
    void draw(SDL_Renderer* renderer, int x, int y);

    //! Returns the next capsule that will become the active capsule
    const Capsule &getNextCapsule() const;

private:
    //! The level of the board, 0<level<20
    int level = 0;

    //! The state of the board
    BoardState boardState{};

    //! The set of Ciruses currently on the board
    std::set<Virus> viruses{};

    //! The set of Blocks and Capsules currently on the board
    std::set<DrawableObject*> blocks{};

    //! The active Capsule being controlled
    Capsule activeCapsule;

    //! The next capsule to become the active Capsule
    Capsule nextCapsule;

    //! Keeps track of which cells on the board are filled for collisions
    Cell board[BOARD_WIDTH_CELLS][BOARD_HEIGHT_CELLS]{}; //TODO: delete if don't use
};


#endif //DRMARIO_BOARD_H
