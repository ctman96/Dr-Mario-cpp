/*!
 * @author: Cody Newman
 *
 * Created on: 17/06/2018
 */

#include "Board.h"

using namespace std;

/*!
 * Initializes the board, setting it up depending
 * on the game level provided.
 * @param level an integer representing the game level
 */
void Board::init(int level) {
    boardState = BoardState::active;
    this->level = level;
    generateLevel();
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
            updateActive();
            break;
        case BoardState::updating:
            updateBlocks();
            clearMatches();
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
    /*auto itc = capsules.begin();
    for(int i = 0; i < capsules.size(); i++){
        itc->get()->draw(renderer);
        next(itc);
    }*/
    activeCapsule.draw(renderer);
}

const Capsule &Board::getNextCapsule() const {
    return nextCapsule;
}

/*!
 * Generates the set of viruses for the board's
 * difficulty level.
 */
void Board::generateLevel() {
    if(level < 0){
        level = 0;
    }
    if (level > 20){
        level = 20;
    }
    //TODO Generate Viruses, create starting capsule
}

/*!
 * Updates the positions of all blocks, dropping them if there
 * are no collisions
 */
void Board::updateBlocks() {
    auto itb = blocks.end();
    for (int i = 0; i < blocks.size(); i++){
        //TODO update all block positions, checking for collisions
        next(itb);
    }
}

/*!
 * Clears any horizontal or vertical sequences of
 * same coloured blocks and updates score depending.
 */
void Board::clearMatches() {
    // TODO check lines, delete, add score
}

/*!
 * Updates the position of the active capsule,
 * dropping it down a row if there is no collision
 */
void Board::updateActive() {
    // TODO drop the active capsule, checking collisions
}


