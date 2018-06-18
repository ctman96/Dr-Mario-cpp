//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_CAPSULE_H
#define DRMARIO_CAPSULE_H

#include "Block.h"

class Capsule : public DrawableObject{
private:
    int rotation;

public:
    int getRotation() const;

    void setRotation(int rotation);

    void draw(SDL_Renderer *renderer) override;
};


#endif //DRMARIO_CAPSULE_H
