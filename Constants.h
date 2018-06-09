//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_CONSTANTS_H
#define DRMARIO_CONSTANTS_H

#endif //DRMARIO_CONSTANTS_H

// Width and Height of the board in Cells
const int BOARD_WIDTH_CELLS = 8;
const int BOARD_HEIGHT_CELLS = 16;

// Pixel size of one edge of a Cell
const int CELL_PIXELS = 16;

// Pixel size of the board height/width
constexpr int BOARD_WIDTH = BOARD_WIDTH_CELLS * CELL_PIXELS;
constexpr int BOARD_HEIGHT = BOARD_HEIGHT_CELLS * CELL_PIXELS;