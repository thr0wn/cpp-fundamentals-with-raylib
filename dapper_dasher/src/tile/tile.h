#pragma once
#include "game/game-emitter.h"
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

  void setTexture(Texture texture);

  void draw(Vector2 position, Color color);
  static void draw(Tile tile, Vector2 position, Color color);
};

class TileAnimation {
public:
  int sprite;
  int spriteTotal;
  int spriteRowSize;
};
} // namespace game
