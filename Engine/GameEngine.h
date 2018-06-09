//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_GAMEENGINE_H
#define DRMARIO_GAMEENGINE_H


class GameState;

class GameEngine {
public:
    void init();
    void terminate();

    void changeState(GameState *state);

    void handle();
    void update();
    void draw();

    bool isRunning(){return running;}
    void quit() {running = false;}

private:
    bool running;
    GameState *state;
};


#endif //DRMARIO_ENGINE_H
