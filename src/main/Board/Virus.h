//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_VIRUS_H
#define DRMARIO_VIRUS_H

#include "Block.h"

class Virus : public Block {
public:
    void draw(SDL_Renderer *renderer) override;
};


#endif //DRMARIO_VIRUS_H
