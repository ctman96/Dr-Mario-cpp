//! Provides public enums used throughout the game
/*!
 *  This file provides consolidated public declarations
 *  of enumerations that are used throughout the game.
 *
 *  @author: Cody Newman
 *
 *  Created on: 19/06/2018
 */

#ifndef DRMARIO_ENUMS_H
#define DRMARIO_ENUMS_H

//! Speeds for gameplay
enum class Speed {low, med, hi};

//! Music choices
enum class Music {fever, chill, off};

//! Colours of blocks/capsules/viruses
enum class Color {red, blue, yellow};

//! 90 degree rotations of an object
enum class Rotation {l, u, r, d};

//! Movement options
enum class Move {l, r, cc, ccw};

//! States of a board cell
enum class Cell {empty, filled}; //TODO: delete if remains unused


#endif //DRMARIO_ENUMS_H
