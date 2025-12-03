#pragma once
#include "tile/tile.hpp"

namespace tileService {
extern const char *textureUrls[];
extern Texture2D textures[NUMBER_OF_TEXTURES];

void start();
void stop();
void draw(Texture texture, Tile tile, Vector2 position);
}; // namespace tileService
