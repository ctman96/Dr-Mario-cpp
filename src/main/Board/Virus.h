//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_VIRUS_H
#define DRMARIO_VIRUS_H

#include "Block.h"

class Virus : public DrawableObject {
public:
    void draw(SDL_Renderer *renderer) const override;
private:
    Color color;
};


#endif //DRMARIO_VIRUS_H
