/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#include <SDL_timer.h>
#include "AnimatedSprite.h"

using namespace std;

AnimatedSprite::AnimatedSprite(const SDL_Rect *clip) : Sprite(clip) {
    repeat = false, speed = false, on = false;
    curFrame = frames.begin();
}

AnimatedSprite::AnimatedSprite(list<const SDL_Rect *> frames, int speed, bool repeat) :
        Sprite(frames.front()),frames(frames),speed(speed), repeat(repeat) {
    on = false;
}

AnimatedSprite::~AnimatedSprite() {
    //TODO
}

void AnimatedSprite::render(GameRenderer* renderer, int x, int y) {
    if(on){
        int ticks = SDL_GetTicks();
        // Change frame if enough time has passed, based on speed
        if(ticks-lastTick > 1000/speed){
            // Playing normally
            if(curFrame != frames.end()) {
                curFrame++;
            } else if (repeat){
                curFrame = frames.begin();
            }
        }
    }
    clip = *curFrame;
    Sprite::render(renderer, x, y);
}

void AnimatedSprite::play() { on = true; }

void AnimatedSprite::pause() { on = false; }

