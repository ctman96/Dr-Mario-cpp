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

template <class T>
bool GameUtils::setContains(const set<T>& set, T t){
    return set.find(t) != set.end();
}

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
    Color color = colorFromInt(c);

    // Move across rows and up until virus is placed or reach the top
    while(true){
        Virus v(x,y,color);
        // If position is empty, insert virus
        if(viruses.find(v) == viruses.end() && checkColors(viruses, v)){
            viruses.insert(v);
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
 * Checks if it is safe to insert a virus at a position,
 * in regards to the colors of the viruses around it
 *  (ensuring a board doesn't start with groups of 4+
 *  viruses of the same color in a row).
 * @param viruses the set of viruses being checked against
 * @param v the viruses to be inserted. Color may be changed
 * @return true if safe to insert, false if not
 */
bool GameUtils::checkColors(const set<Virus>& viruses, Virus& v){
    // Check in each direction, return true if
    set<Color> c{};

    //Check Left
    auto it = viruses.find(Virus(v.x-2,v.y, v.color));
    if (it != viruses.end()){
        c.insert((*it).color);
    }
    //Check Up
    it = viruses.find(Virus(v.x,v.y+2, v.color));
    if (it != viruses.end()){
        c.insert((*it).color);
    }
    //Check Right
    it = viruses.find(Virus(v.x+2, v.y, v.color));
    if (it != viruses.end()){
        c.insert((*it).color);
    }
    //Check Down
    it = viruses.find(Virus(v.x,v.y-2, v.color));
    if (it != viruses.end()){
        c.insert((*it).color);
    }

    bool red = setContains(c, Color::red);
    bool blue = setContains(c, Color::blue);
    bool yellow = setContains(c, Color::yellow);

    // Ignore this cell
    if (red && blue && yellow){
        return false;
    }

    // Safe to add
    if(!setContains(c, v.color)){
        return true;
    }

    // else Change color
    switch(v.color){
        case Color::yellow:
            v.color = Color::blue;
            break;
        case Color::red:
            v.color = Color::yellow;
            break;
        case Color::blue:
            v.color = Color::red;
            break;
    }
    return false;
}

/*!
 * Returns a capsule with random color values
 * @return the generated capsule
 */
Capsule GameUtils::generateCapsule(int x, int y) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> randC(0,2);

    int c1 = randC(generator);
    int c2 = randC(generator);

    Color color1 = colorFromInt(c1);
    Color color2 = colorFromInt(c2);
    return Capsule(x,y, color1, color2);
}

/*!
 * Updates the positions of all blocks and capsules, dropping them if there
 * are no collisions
 * @param viruses the set of Viruses on the board
 * @param blocks the set of Blocks on the board
 * @param capsules the set of Capsules on the board
 */
void GameUtils::updateBlocks(const set<Virus> &viruses, set<Block> &blocks, set<Capsule>& capsules) {
    auto itb = blocks.end();
    for (int i = 0; i < blocks.size(); i++){
        //TODO update all block positions, checking for collisions
        next(itb);
    }
}

/*!
 * Clears any horizontal or vertical sequences of
 * same coloured blocks/capsules/viruses and updates score depending.
 * @param viruses the set of Viruses on the board
 * @param blocks the set of Blocks on the board
 * @param capsules the set of Capsules on the board
 */
void GameUtils::clearMatches(set<Virus> &viruses, set<Block> &blocks, set<Capsule>& capsules) {
    // TODO check lines, delete, add score
}

/*!
 * Updates the position of the active capsule,
 * dropping it down a row if there is no collision
 * @param viruses the set of Ciruses on the board
 * @param blocks the set of Blocks on the board
 * @param capsules the set of Capsules on the board
 * @param activeCapsule the active Capsule being moved
 */
void GameUtils::updateActive(const set<Virus> &viruses, const set<Block> &blocks, set<Capsule>& capsules,
                             Capsule &activeCapsule)
{
    // TODO drop the active capsule, checking collisions
    checkCollisions(viruses, blocks, capsules, activeCapsule, Move::d);
}

/*!
 * Returns the Color corresponding to the int value given
 * @param c the int value to be converted to a Color.
 * @return the Color corresponding to c
 */
Color GameUtils::colorFromInt(int c){
    c = c%3;
    switch(c){
        case 0:
            return Color::yellow;
        case 1:
            return Color::red;
        case 2:
            return Color::blue;
        default:
            printf("Invalid color number generated, using default");
            return Color::red;
    }
}

/*!
 * Checks for collisions if the activeCapsule is changed with Move move.
 * @param viruses the set of Viruses on the board
 * @param blocks the set of Blocks on the board
 * @param capsules the set of Capsules on the board
 * @param activeCapsule the Capsule being moved
 * @param move the desired Move
 * @return true if collides, false otherwise
 */
bool GameUtils::checkCollisions(const std::set<Virus> &viruses, const std::set<Block> &blocks,
                                set<Capsule>& capsules, Capsule &activeCapsule, Move move) {
    switch(move){
        case Move::d:
            // TODO
            break;
        case Move::l:
            // TODO
            break;
        case Move::r:
            // TODO
            break;
        case Move::cc:
            switch(activeCapsule.getRotation()){
                case Rotation::l:
                    // TODO
                    break;
                case Rotation::u:
                    // TODO
                    break;
                case Rotation::r:
                    // TODO
                    break;
                case Rotation::d:
                    // TODO
                    break;
            }
            break;
        case Move::ccw:
            switch(activeCapsule.getRotation()){
                case Rotation::l:
                    // TODO
                    break;
                case Rotation::u:
                    // TODO
                    break;
                case Rotation::r:
                    // TODO
                    break;
                case Rotation::d:
                    // TODO
                    break;
            }
            break;
    }
    return false;
}

/*!
 * Checks if a given x,y position is free of Viruses, Blocks, and Capsules
 * @param viruses the set of Viruses on the board
 * @param blocks the set of Blocks on the board
 * @param capsules the set of Capsules on the board
 * @param x the x coordinate of the cell to check
 * @param y the y coordinate of the cell to check
 * @return true if the cell is free
 */
bool GameUtils::checkFree(const std::set<Virus> &viruses, const std::set<Block> &blocks, set<Capsule>& capsules,
                          int x, int y) {
    // TODO
    return false;
}
