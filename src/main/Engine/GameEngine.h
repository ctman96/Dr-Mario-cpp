//! The state machine which handles running and swapping game states
/*!
 * The GameEngine class is a basic state machine designed to run
 * the different GameStates that make up the game.
 *
 * @author: Cody Newman
 *
 * Created on: 8/6/2018
 */

#ifndef DRMARIO_GAMEENGINE_H
#define DRMARIO_GAMEENGINE_H

#include <SDL_mixer.h>
#include "SDL.h"

class GameState;

class GameEngine {
public:
    //! Initializes the GameEngine
    void init();

    //! Cleans up the GameEngine in preparation for deletion
    void terminate();

    //! Switches to a new state
    /*!
     * @param state pointer to the state to be switched to
     */
    void changeState(GameState *state);

    //! Event Handling
    void handle();
    //! Updates the state
    void update();
    //! Renders the state
    void draw();

    //! Returns whether the engine is currently running
    bool isRunning(){return running;}
    //! Sets the engine to stop running, for breaking out of loop
    void quit() {running = false;}

    //! The program's window
    SDL_Window* window;
    //! The screen of the window, representing the collection of pixels
    SDL_Surface* screen;
    //! The renderer which handles rendering to the screen
    SDL_Renderer* renderer;
    //! The current loaded audio track
    Mix_Music * music;

private:
    bool running;
    GameState *state;
};


#endif //DRMARIO_ENGINE_H
