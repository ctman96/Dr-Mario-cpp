/*!
 * @author: Cody Newman
 *
 * Created on: 17/06/2018
 */

#include "Board.h"
#include "GameUtils.h"

using namespace std;
using namespace GameUtils;

/*!
 * Initializes the board, setting it up depending
 * on the game level provided.
 * @param level an integer representing the game level
 */
void Board::init(int level) {
    boardState = BoardState::active;
    this->level = level;
    viruses = generateLevel(level);
}

/*!
 * Cleans up the game board, clearing
 * away all pieces in preparation for
 * deletion or a new level
 */
void Board::clear() {
    viruses.clear();
    blocks.clear();
    //capsules.clear();
}

/*!
 * Updates the state of the board. If the board is active, it drops
 * the activeBlock. If the board is updating, it drops any blocks that
 * aren't colliding, as well as checks for matches to be cleared for points.
 */
void Board::update() {
    switch(boardState){
        case BoardState::active:
            // TODO create new activeCapsule if necessary
            updateActive(viruses, blocks, activeCapsule);
            break;
        case BoardState::updating:
            updateBlocks(viruses, blocks);
            clearMatches(viruses, blocks);
            break;
    }
}

/*!
 * Draws the viruses, blocks, and capsules contained by the board
 *
 * @param renderer The renderer to be used
 * @param x The x coordinate of the top left corner of the board
 * @param y The y coordinate of the top left corner of the board
 */
void Board::draw(SDL_Renderer* renderer, int x, int y) {
    auto itv = viruses.begin();
    for( int i = 0; i < viruses.size(); i++){
        itv->draw(renderer);
        next(itv);
    }
    auto itb = blocks.begin();
    for(int i = 0; i < blocks.size(); i++){
        (*itb)->draw(renderer);
        next(itb);
    }
    activeCapsule.draw(renderer);
}

const Capsule &Board::getNextCapsule() const {
    return nextCapsule;
}