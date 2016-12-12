#ifndef GAME_H
#define GAME_H
#include <memory>
#include <fstream>
#include <map>
#include "puzzle.hpp"

struct EventHandler {
    int tile_x = -1, tile_y;        // coodrinates of first selected tile

    // Read events from SDL and process them
    void poll_events();

    // Methods to use pressed keys registry
    void keydown(int keysym);
    void keyup(int keysym);
    bool isDown(int keysym);

private:
    // pressed keys registry
    std::map<int, bool> keymap;
    SDL_Event e;

    void process_click();
    void process_key_press();
};

struct LevelLoader {
    std::ifstream levelsFile;
public:
    LevelLoader();
    std::unique_ptr<Puzzle> next();
    std::unique_ptr<Puzzle> nextFromDialog();
};

// Class with game logic
class Game {
    EventHandler eventHandler;
    void draw();
    bool done = false;
public:
    LevelLoader levelLoader;
    std::unique_ptr<Puzzle> currentLevel;

    void run();
    void stop();
};

extern Game* game;

#endif // GAME_H
