#pragma once
#include "raylib.h"
#include <map>

#define NUMBER_OF_TEXTURES 5

namespace game {
typedef enum GameTexture {
  TEXTURE_SCARFY = 0,
  TEXTURE_FAR_BUILDING,
  TEXTURE_BACK_BUILDING,
  TEXTURE_NEAR_BUILDING,
  TEXTURE_NEBULA
} GameTexture;

class Tile: public Rectangle {
public:
  float x;
  float y;
  float width;
  float height;
  Texture2D texture;

  void setTexture(const Texture &texture);
};

class TileAnimation {
public:
  int sprite;
  int spriteTotal;
  int spriteRowSize;
};
} // namespace game
