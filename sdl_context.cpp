#include "sdl_context.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

// Global SDL context
SDL_Context* context;

SDL_Context::SDL_Context(int w, int h) {
    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << SDL_GetError() << endl;
        exit(1);
    }

    // Initialize SDL2_image
    int imgInitFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgInitFlags) & imgInitFlags)) {
        cerr << IMG_GetError() << endl;
        exit(1);
    }

    // Create window
    window = SDL_CreateWindow("Puzzle",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              w, h,
                              SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        cerr << SDL_GetError() << endl;
        exit(1);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        cerr << SDL_GetError() << endl;
        exit(1);
    }

    // Set renderer background color to white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

SDL_Context::~SDL_Context() {
    if(renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if(window != nullptr) {
       SDL_DestroyWindow(window);
    }
}
