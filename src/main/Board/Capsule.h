//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_CAPSULE_H
#define DRMARIO_CAPSULE_H

#include "Block.h"
#include "../GameUtils.h"

class Capsule : public DrawableObject{
private:
    Color c1{};
    Color c2{};
    int rotation = 0;

public:
    int getRotation() const;

    void setRotation(int rotation);

    void draw(SDL_Renderer *renderer) const override;
};


#endif //DRMARIO_CAPSULE_H
