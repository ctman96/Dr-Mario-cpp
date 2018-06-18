//
// Created by Cody on 6/17/2018.
//

#ifndef DRMARIO_DRAWABLEOBJECT_H
#define DRMARIO_DRAWABLEOBJECT_H


#include <SDL_render.h>

class DrawableObject {
public:
    int x=0;

    int y=0;

    bool operator<(const DrawableObject& other) const{
        return (y < other.y) || (y == other.y && x < other.x); //Prioritize y sorting, followed by x
    }

    bool operator==(const DrawableObject& other) const{
        return y == other.y && x == other.x;
    }

    virtual void draw(SDL_Renderer* renderer) const = 0;
};


#endif //DRMARIO_DRAWABLEOBJECT_H
