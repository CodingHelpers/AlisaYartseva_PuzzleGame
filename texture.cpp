#include "texture.hpp"
#include "sdl_context.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
using namespace std;

Texture::Texture() {}

Texture::~Texture() {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}


bool
Texture::load(const std::string& path) {
    // Load image at a specified path
    SDL_Surface* imageSurface = IMG_Load(path.c_str());
    if(imageSurface == nullptr) {
        cerr << IMG_GetError() << endl;
        return false;
    }

    // Create texture from surface
    texture = SDL_CreateTextureFromSurface(context->renderer, imageSurface);
    if(texture == nullptr) {
        cerr << SDL_GetError() << endl;
        return false;
    }

    // Save surface dimensions
    width = imageSurface->w;
    height = imageSurface->h;

    // Unload surfase needed no more
    SDL_FreeSurface(imageSurface);

    return true;
}

void
Texture::render(const SDL_Rect* texture_clip, const SDL_Rect* render_clip) {
    SDL_RenderCopy(context->renderer, texture, texture_clip, render_clip);
}
