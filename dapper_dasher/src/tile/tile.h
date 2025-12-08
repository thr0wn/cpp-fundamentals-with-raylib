#pragma once
#include "raylib.h"

#define TILE_WIDTH 8
#define TILE_HEIGHT 8

#define NUMBER_OF_TEXTURES 5

typedef enum GameTexture {
  TEXTURE_SCARFY = 0,
  TEXTURE_FAR_BUILDING,
  TEXTURE_BACK_BUILDING,
  TEXTURE_NEAR_BUILDING,
  TEXTURE_NEBULA
} GameTexture;

class Tile : Rectangle {
public:
  float x;
  float y;
  float width = TILE_WIDTH;
  float height = TILE_HEIGHT;
};

class TileAnimation {
public:
  int sprite;
  int spriteTotal;
  int spriteRowSize;
};
