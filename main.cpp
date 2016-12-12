#include <iostream>
#include <random>
#include <time.h>
#include "sdl_context.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Seed random number generator (for puzzle shuffling)
    srand(time(NULL));

    // Create new SDL Context (window)
    context = new SDL_Context(1280, 720);
    game    = new Game;

    // Load first level
    game->currentLevel = game->levelLoader.next();
    game->currentLevel->shuffle();

    // Start the game
    game->run();

    // Cleanup and exit
    delete game;
    delete context;
    return 0;
}
