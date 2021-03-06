//! Game state representing Singleplayer gameplay
/*!
 * The SinglePlayerState represents the game state
 * for gameplay with one player
 *
 * @author: Cody Newman
 *
 * Created on: 13/06/2018
 */

#ifndef DRMARIO_SINGLEPLAYERSTATE_H
#define DRMARIO_SINGLEPLAYERSTATE_H

#include "GameState.h"
#include "../../Board/Board.h"

class SinglePlayerState : public GameState {
public:
    //! Constructor, taking in gameplay options
    SinglePlayerState(int level, Speed speed, Music music);

    //! Initializes the state
    void init(GameEngine *game) override;

    //! Cleans up the state
    void terminate() override;

    //! Handles SDL events
    void handle(GameEngine *game) override;

    //! Updates the state of the board
    void update(GameEngine *game) override;

    //! Renders the state
    void draw(GameEngine *game) override;

private:
    //! The game level
    int level;
    //! The game speed
    Speed speed;
    //! The selected music
    Music music;

    //! The spritesheet used in the state
    SDL_Texture* spritesheet;

    //! The current score
    int score;
    //! The top score achieved
    int topscore;

    //! The game board
    Board* board;

    //! Helper for drawing virus sprites
    void drawVirus(SDL_Renderer* renderer, Virus virus);

    //! Helper for drawing block sprites
    void drawBlock(SDL_Renderer* renderer, Block block);

    //! Helper for drawing capsule sprites
    void drawCapsule(SDL_Renderer* renderer, Capsule capsule, int x, int y);

    //! Helper for drawing two digit numbers
    void drawNum(SDL_Renderer* renderer, int num, int x, int y);

    //! Helper for drawing the animated virus display
    void drawVirusDisplayAnimation(SDL_Renderer* renderer);

    //! The x position of the top left corner of the bottem left cell of the board
    int xoffset = 96;
    //! The y position of the top left cornder of the bottem left cell of the board
    int yoffset = 191;
};


#endif //DRMARIO_SINGLEPLAYERSTATE_H
