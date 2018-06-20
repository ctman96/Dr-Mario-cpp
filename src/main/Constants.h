//! Provides constants used throughout the game
/*!
 * Consolidates all constant values that are used
 * throughout the game.
 *
 * @author: Cody Newman
 *
 * Created on 08/06/2018
 */

#ifndef DRMARIO_CONSTANTS_H
#define DRMARIO_CONSTANTS_H

#include <string>

//TODO maybe load some of these adjustable settings from a config file?

//! The smallest width of the screen at the base scale, based on sprite size
static const int BASE_WIDTH = 256;
//! The smallest heigh tof the screen at the base scale, based on sprite size
static const int BASE_HEIGHT = 224;

//! The scaling multiplier to be used
static const int SCALING = 2;
//! The scaling method to be used by SDL
/*!
 * Value of "0" provides nearest pixel sampling.
 * Value of "1" provides linear filtering.
 * Value of "2" provides anisotropic filtering
 */
static const char *SCALING_QUALITY = "1";

//! The width of the screen with scaling
static constexpr int SCREEN_WIDTH = BASE_WIDTH * SCALING;
//! The height of the screen with scaling
static constexpr int SCREEN_HEIGHT = BASE_HEIGHT * SCALING;

//! The title of the game, namely for the program window
static const char *TITLE = "Dr Mario";


//! The width of a game board, in cells
static const int BOARD_WIDTH_CELLS = 8;
//! The height of a game board, in cells
static const int BOARD_HEIGHT_CELLS = 16;

//! The size, in pixels, of a side of a cell
static const int CELL_PIXELS = 16;

//! The width, in pixels of a board
static constexpr int BOARD_WIDTH = BOARD_WIDTH_CELLS * CELL_PIXELS;
//! The height, in pixels, of a board
static constexpr int BOARD_HEIGHT = BOARD_HEIGHT_CELLS * CELL_PIXELS;

#endif //DRMARIO_CONSTANTS_H