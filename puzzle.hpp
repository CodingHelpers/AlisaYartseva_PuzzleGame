#ifndef PUZZLE_H
#define PUZZLE_H
#include <SDL2/SDL.h>
#include <texture.hpp>
#include <vector>

// Tile structure containing real coordinates and clips info
struct Tile {
    int x, y;
    SDL_Rect texture_clip;
    SDL_Rect render_clip;

    Tile(int x, int y) : x(x), y(y) {}

    void calculateTextureClip(int tileWidth, int tileHeight);
    void calculateRenderClip(int x, int y, int tileWidth, int tileHeight);
};

// Define new type for two-dimensional array of maps
typedef std::vector<std::vector<Tile>> TileMap;

class Puzzle {
    TileMap tileMap;

    int netSize;

    int textureTileW;
    int textureTileH;
    int renderTileW;
    int renderTileH;

    bool done;

    void calculateTileMap();
    bool checkIfSolved();
public:
    Texture texture;
    Puzzle(const std::string& path);
    Puzzle(const std::string& path, int netSize);

    // Swap two tiles
    void swap(size_t x1, size_t y1, size_t x2, size_t y2);

    // Change network size
    void setNetSize(int size);

    // Shuffle tiles
    void shuffle();

    // Render on screen
    void render();

    Tile& tile(int x, int y) {
        return tileMap[y][x];
    }

    int getNetSize() {
        return netSize;
    }

    int getTextureTileWidth() {
        return textureTileW;
    }

    int getTextureTileHeight() {
        return textureTileH;
    }

    int getRenderTileWidth() {
        return renderTileW;
    }

    int getRenderTileHeight() {
        return renderTileH;
    }

    bool isDone() {
        return done;
    }
};

#endif // PUZZLE_H
