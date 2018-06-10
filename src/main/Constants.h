//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_CONSTANTS_H
#define DRMARIO_CONSTANTS_H

#include <string>

//TODO maybe load some of these adjustable settings from a config file?

// The smallest width of the screen
// Shouldn't be touched
static const int BASE_WIDTH = 256;
static const int BASE_HEIGHT = 224;

static const int SCALING = 2;
static const char *SCALING_QUALITY = "1";   //0 = nearest pixel sampling, 1 = linear filtering, 2 = anisotropic filtering

static constexpr int SCREEN_WIDTH = BASE_WIDTH * SCALING;
static constexpr int SCREEN_HEIGHT = BASE_HEIGHT * SCALING;

static const char *TITLE = "Dr Mario";


// Width and Height of the board in Cells
static const int BOARD_WIDTH_CELLS = 8;
static const int BOARD_HEIGHT_CELLS = 16;

// Pixel size of one edge of a Cell
static const int CELL_PIXELS = 16;

// Pixel size of the board height/width
static constexpr int BOARD_WIDTH = BOARD_WIDTH_CELLS * CELL_PIXELS;
static constexpr int BOARD_HEIGHT = BOARD_HEIGHT_CELLS * CELL_PIXELS;

#endif //DRMARIO_CONSTANTS_H