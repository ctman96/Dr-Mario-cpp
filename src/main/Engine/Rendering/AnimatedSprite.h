//! Represents a sprite animation with multiple frames
/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#ifndef DRMARIO_ANIMATEDSPRITE_H
#define DRMARIO_ANIMATEDSPRITE_H


#include "Sprite.h"
#include <list>

class AnimatedSprite : public Sprite {
public:
    explicit AnimatedSprite(const SDL_Rect *clip);

    explicit AnimatedSprite(std::list<const SDL_Rect *>, int speed = 1, bool repeat=true);

    ~AnimatedSprite() override;

    void render(GameRenderer * renderer, int x, int y) override;

    void play();

    void pause();

private:
    //! The locations of each frame of the animation on the spritesheet
    std::list<const SDL_Rect*> frames;

    //! Whether or not to loop the animation from the start
    bool repeat;

    //! Speed of the animation, in frames per secon
    int speed;

    //! If the animation is currently playing
    bool on;

    //! The previous game tick on which the frame was changed
    int lastTick = 0;

    //! The current frame the animation is on
    std::list<const SDL_Rect*>::iterator curFrame;
};


#endif //DRMARIO_ANIMATEDSPRITE_H
