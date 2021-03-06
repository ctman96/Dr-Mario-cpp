/*!
 * @author: Cody Newman
 *
 * Created on: 17/06/2018
 */

#include <SDL_timer.h>
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
    boardState = BoardState::loading;
    if (level < 0){
        level = 0;
    }
    if (level > 20){
        level = 20;
    }
    this->level = level;

    activeCapsule = generateCapsule(3,15);
    nextCapsule = generateCapsule(3,15);
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
    int ticks = SDL_GetTicks();
    switch(boardState){
        case BoardState::loading:
            if (!((ticks/20)%2)){
                loadTick = true;
            }
            if ((ticks/20)%2 && loadTick) {
                loadBoard();
                loadTick = false;
            }

            break;
        case BoardState::active:
            // TODO create new activeCapsule if necessary
            updateActive(viruses, blocks, capsules, activeCapsule);
            break;
        case BoardState::updating:
            updateBlocks(viruses, blocks, capsules);
            clearMatches(viruses, blocks, capsules);
            break;
        case BoardState::win:
            //TODO
            break;
        case BoardState::loss:
            //TODO
            break;
    }
}

void Board::loadBoard(){
    if(viruses.size() < (level+1)*4){
        while(!generateVirus(viruses, level));
    }
    else{
        boardState = BoardState::active;
    }
}

Board::BoardState Board::getBoardState() const {
    return boardState;
}

const Capsule &Board::getNextCapsule() const {
    return nextCapsule;
}

Capsule &Board::getActiveCapsule() {
    return activeCapsule;
}

const set<Virus> &Board::getViruses() const {
    return viruses;
}

const set<Block> &Board::getBlocks() const {
    return blocks;
}

const set<Capsule> &Board::getCapsules() const {
    return capsules;
}