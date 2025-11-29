#pragma once
#include "tile.hpp"

class TileController {
public:
  static Texture2D textures[NUMBER_OF_TEXTURES];
  static void start();
  static void draw(Tile tile, Vector2 position, Texture texture);
};
