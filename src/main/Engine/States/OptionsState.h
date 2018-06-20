//! Game state representing game option selection
/*!
 * The OptionState represents the state of the
 * options menu for selecting gameplay settings
 *
 * @author: Cody Newman
 *
 * Created on: 10/06/2018
 */

#ifndef DRMARIO_OPTIONSSTATE_H
#define DRMARIO_OPTIONSSTATE_H

#include "GameState.h"
#include "../../enums.h"

class OptionsState : public GameState {
public:
    //! Constructs option state depending on multiplayer flag
    explicit OptionsState(bool twoplayer);

    //! Initializes the state
    void init(GameEngine *game) override;

    //! Cleans up the state
    void terminate() override;

    //! Handles SDL Events
    void handle(GameEngine *game) override;

    //! Updates the state of the menu
    void update(GameEngine *game) override;

    //! Renders the options menu
    void draw(GameEngine *game) override;

    //! Possible menu selections
    /*!
     * Represents the different sections of
     * the menu that can be switched between
     */
    enum class Selection {level, speed, music};

private:
    //! Flag declaring whether to display the 1player or 2player menu
    bool twoplayer;

    //! The currently selected menu item
    Selection selection;
    //! The level value selected by player 1
    int level1 = 0;
    //! The level value selected by player 2
    int level2 = 0;
    //! The speed value selected by player 1
    Speed speed1 = Speed::med;
    //! The speed value selected by player 2
    Speed speed2 = Speed::med;
    //! The selected music value
    Music music = Music::fever;

    //! The spritesheet used by the menu
    SDL_Texture* spritesheet;
    //! The sprite atlas for the spritesheet
    SDL_Rect sprites[37];

    void selectionDown();
    void selectionUp();

    void incLevel(int& level);
    void decLevel(int& level);

    void incSpeed(Speed& speed);
    void decSpeed(Speed& speed);

    void incMusic();
    void decMusic();

    void loadSprites();

    //! Displays a two digit number
    void renderNum(SDL_Renderer* renderer, int level, int x, int y);
};


#endif //DRMARIO_OPTIONSSTATE_H
