//! Game state representing the main menu
/*!
 * The MainMenu represents the game state
 * for the opening splash screen
 *
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#ifndef DRMARIO_MAINMENUSTATE_H
#define DRMARIO_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState  : public GameState{
public:
    //! Initializes the state
    void init(GameEngine *game) override;

    //! Cleans up the state
    void terminate() override;

    //! Handles SDL events
    void handle(GameEngine *game) override;

    //! Updates the state of the menu
    void update(GameEngine *game) override;

    //! Renders the state
    void draw(GameEngine *game) override;

private:
    //! The spritesheet used in the state
    SDL_Texture* spritesheet;

    //! Position of the cursor
    bool cursor = false;
};


#endif //DRMARIO_MAINMENUSTATE_H
