//! Abstract class representing a state of the game
/*!
 * This abstract class provides the base for GameStates,
 * the states used by the game engine state machine.
 *
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#ifndef DRMARIO_GAMESTATE_H
#define DRMARIO_GAMESTATE_H

#include "../GameEngine.h"

class GameState {
public:
    //! Initializes the state
    virtual void init(GameEngine *game) = 0;

    //! Cleans up the state
    virtual void terminate() = 0;

    //! Handles any SDL Events
    virtual void handle(GameEngine *game) = 0;

    //! Updates the state
    virtual void update(GameEngine *game) = 0;

    //! Renders the state
    virtual void draw(GameEngine *game) = 0;

    //! Default destructor
    virtual ~GameState() = default;
};


#endif //DRMARIO_GAMESTATE_H
