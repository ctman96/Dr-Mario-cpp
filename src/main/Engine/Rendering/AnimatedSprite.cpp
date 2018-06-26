//! Represents a sprite animation with multiple frames
/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#include <SDL_timer.h>
#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Texture *spritesheet, SDL_Rect *clip, SDL_Renderer *renderer) : Sprite(spritesheet,
                                                                                                          clip,
                                                                                                          renderer) {
    repeat = false, speed = false, on = false;
}

AnimatedSprite::AnimatedSprite(SDL_Texture *spritesheet, std::vector<SDL_Rect *> frames, SDL_Renderer *renderer,
                               bool repeat, int speed) : Sprite(spritesheet, frames[0], renderer),
                                                                        frames(frames), repeat(repeat),
                                                                        speed(speed) {
    on = false;
}

AnimatedSprite::~AnimatedSprite() {
    //TODO
}

void AnimatedSprite::render(int x, int y) {
    if(on){
        int ticks = SDL_GetTicks();
        // Change frame if enough time has passed, based on speed
        if(ticks-lastTick > 1000/speed){
            // Playing normally
            if(curFrame < frames.size()-1) {
                curFrame++;
            } else if (repeat){
                curFrame = 0;
            }
        }
    }
    clip = frames[curFrame];
    Sprite::render(x, y);
}

void AnimatedSprite::play() { on = true; }

void AnimatedSprite::pause() { on = false; }

