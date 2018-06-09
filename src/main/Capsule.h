//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_CAPSULE_H
#define DRMARIO_CAPSULE_H

#include "Block.h"

class Capsule {
private:
    Block b1;
    Block b2;
    int rotation;

public:
    const Block &getB1() const;

    const Block &getB2() const;

    int getRotation() const;

    void setRotation(int rotation);
};


#endif //DRMARIO_CAPSULE_H
