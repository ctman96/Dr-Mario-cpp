//! Abstract class for objects meant to be drawn
/*!
 * Provides a basis for game objects that need
 * an x,y position and the ability to be drawn
 *
 * @author: Cody Newman
 *
 * Created on: 17/06/2018
 */

#ifndef DRMARIO_DRAWABLEOBJECT_H
#define DRMARIO_DRAWABLEOBJECT_H


#include <SDL_render.h>
#include "../Engine/Rendering/Sprite.h"

class DrawableObject {
public:
    int x=0;

    int y=0;

    DrawableObject() : x(0),y(0), sprite(nullptr) {}

    DrawableObject(int x, int y) : x(x), y(y), sprite(nullptr) {}

    virtual ~DrawableObject(){
        //delete(sprite); //TODO: Why does this segfault?
    }

    //! Draws the sprite at x and y on the renderer
    virtual void draw(GameRenderer* renderer, int x, int y){
        if (sprite != nullptr) {
            sprite->render(renderer, x, y);
        }
    }

    //! Lessthan comparison based on y and x value
    /*!
     * Lessthan comparator which compares two Drawable objects and returns true
     * for a smaller y, or same y and smaller x
     * @param other the other object being compared
     * @return whether this object has a lower value than the other
     */
    bool operator<(const DrawableObject& other) const{
        return (y < other.y) || (y == other.y && x < other.x); //Prioritize y sorting, followed by x
    }

    //! equal comparison based on x,y value
    /*!
     * Checks whether two DrawableObjects are equal, depending on
     * if their x and y values match
     * @param other the other object being compared
     * @return whether the x and y values of both objects are equal
     */
    virtual bool operator==(const DrawableObject& other) const{
        return y == other.y && x == other.x;
    }

protected:
    Sprite* sprite;
};


#endif //DRMARIO_DRAWABLEOBJECT_H
