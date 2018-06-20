/*!
 * @author: Cody Newman
 *
 * Created on: 20/06/2018
 */

#include "GameUtils.h"

/*!
 * Generates the set of viruses for the board's
 * difficulty level.
 */
std::set<Virus> GameUtils::generateLevel(int level) {
    if(level < 0){
        level = 0;
    }
    if (level > 20){
        level = 20;
    }
    //TODO Generate Viruses, create starting capsule
    return std::set<Virus>();
}

/*!
 * Updates the positions of all blocks, dropping them if there
 * are no collisions
 */
void GameUtils::updateBlocks(const std::set<Virus> &viruses, std::set<DrawableObject *> &blocks) {
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
void GameUtils::clearMatches(std::set<Virus> &viruses, std::set<DrawableObject *> &blocks) {
    // TODO check lines, delete, add score
}

/*!
 * Updates the position of the active capsule,
 * dropping it down a row if there is no collision
 */
void GameUtils::updateActive(const std::set<Virus> &viruses, const std::set<DrawableObject *> &blocks,
                             Capsule &activeCapsule)
{
    // TODO drop the active capsule, checking collisions
}
