#pragma once
#include "tile/tile.hpp"

class TileService {
public:
  static Texture2D textures[NUMBER_OF_TEXTURES];
  static const char *textureUrls[NUMBER_OF_TEXTURES];
  static void start();
  static void stop();
  static void draw(Texture texture, Tile tile, Vector2 position);
};
