//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_BLOCK_H
#define DRMARIO_BLOCK_H

#include "DrawableObject.h"

enum class Color {red, blue, yellow};

class Block : public DrawableObject{
public:
    Color getColor() const;

    void draw(SDL_Renderer *renderer) override;

private:
    Color color;
};


#endif //DRMARIO_BLOCK_H
