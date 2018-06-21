/*!
 * @author: Cody Newman
 *
 * Created on: 20/06/2018
 */

#include <random>
#include <chrono>
#include "GameUtils.h"
#include "../Constants.h"

using namespace std;

/*!
 * Generates the set of viruses for the board's
 * difficulty level.
 */
bool GameUtils::generateVirus(set<Virus>& viruses, int level) {
    if(level <= 0){
        level = 0;
    }
    if (level > 20){
        level = 20;
    }
    // Determine the maximum row that can contain viruses
    int maxrow = 10;
    if (15 <= level && level <= 16){
        maxrow = 11;
    }
    else if (17 <= level && level <= 18){
        maxrow = 12;
    }
    else if (level >= 19){
        maxrow = 13;
    }

    // Number of viruses to generate
    int numViruses = (level+1)*4;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    uniform_int_distribution<int> randX(0,BOARD_WIDTH_CELLS-1);
    uniform_int_distribution<int> randY(0,maxrow-1);
    uniform_int_distribution<int> randC(0,2);


    //Generate x and y
    int x = randX(generator);
    int y = randY(generator);

    // Generate color
    int c = randC(generator);
    Color color;
    switch(c){
        case 0:
            color = Color::yellow;
            break;
        case 1:
            color = Color::red;
            break;
        case 2:
            color = Color::blue;
            break;
        default:
            printf("Invalid color number generated, using default");
            color = Color::red;
            break;
    }

    // Move across rows and up until virus is placed or reach the top
    while(true){
        // If position is empty, insert virus
        if(viruses.find(Virus(x,y,color)) == viruses.end()){
            //TODO: Check to ensure no sets of four matching colours
            viruses.insert(Virus(x,y,color));
            return true;
        }
        else{
            x++;
            if(x == BOARD_WIDTH_CELLS){
                x = 0;
                y++;
                if(y==maxrow){
                    break;
                }
            }
        }
    }
    return false;
}

/*!
 * Updates the positions of all blocks, dropping them if there
 * are no collisions
 */
void GameUtils::updateBlocks(const set<Virus> &viruses, set<DrawableObject *> &blocks) {
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
void GameUtils::clearMatches(set<Virus> &viruses, set<DrawableObject *> &blocks) {
    // TODO check lines, delete, add score
}

/*!
 * Updates the position of the active capsule,
 * dropping it down a row if there is no collision
 */
void GameUtils::updateActive(const set<Virus> &viruses, const set<DrawableObject *> &blocks,
                             Capsule &activeCapsule)
{
    // TODO drop the active capsule, checking collisions
}
