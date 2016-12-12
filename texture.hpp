#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <string>

class Texture {
    SDL_Texture* texture = nullptr;
    int width, height;
public:
    Texture();
    ~Texture();

    // Load texture from image
    bool load(const std::string& path);

    // Render texture with custom clips
    void render(const SDL_Rect* texture_clip = nullptr, const SDL_Rect* render_clip = nullptr);

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }
};

#endif // TEXTURE_H
