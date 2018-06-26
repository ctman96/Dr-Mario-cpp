/*!
 * @author: Cody Newman
 *
 * Created on: 25/06/2018
 */

#ifndef DRMARIO_ANIMATEDSPRITE_H
#define DRMARIO_ANIMATEDSPRITE_H


#include "Sprite.h"
#include <vector>

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite(SDL_Texture *spritesheet, SDL_Rect *clip, SDL_Renderer *renderer);

    AnimatedSprite(SDL_Texture *spritesheet, std::vector<SDL_Rect *>, SDL_Renderer *renderer,
                   bool repeat=true, int speed = 1);

    virtual ~AnimatedSprite();

    void render(int x, int y) override;

    void play();

    void pause();

private:
    //! The locations of each frame of the animation on the spritesheet
    std::vector<SDL_Rect*> frames;

    //! Whether or not to loop the animation from the start
    bool repeat;

    //! Speed of the animation, in frames per secon
    int speed;

    //! If the animation is currently playing
    bool on;

    //! The previous game tick on which the frame was changed
    int lastTick = 0;

    //! The current frame the animation is on
    int curFrame = 0;
};


#endif //DRMARIO_ANIMATEDSPRITE_H
