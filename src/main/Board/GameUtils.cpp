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
std::set<Virus> GameUtils::generateLevel(int level) {
    if(level < 0){
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
    else if (level == 19){
        maxrow = 13;
    }

    // Number of viruses to generate
    int numViruses = level*4;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    uniform_int_distribution<int> randX(0,BOARD_WIDTH_CELLS-1);
    uniform_int_distribution<int> randY(0,maxrow-1);
    uniform_int_distribution<int> randC(0,2);

    set<Virus> viruses{};

    for (int i = 0; i < numViruses; i++){
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

        Virus v(x,y, color);

        // Check if there is already a virus at x,y
        if(viruses.find(v) != viruses.end()){
            viruses.insert(v);
        }
        else{
            //TODO: handle colllisions in generation
        }
    }


    return viruses;
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
