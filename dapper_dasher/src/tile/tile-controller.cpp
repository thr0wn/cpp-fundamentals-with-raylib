#include "tile-controller.hpp"
#include "raylib.h"
#include "tile.hpp"

const char *TileController::textureUrls[] = {
    "resources/textures/scarfy.png", "resources/textures/foreground.png",
    "resources/textures/far-buildings.png",
    "resources/textures/back-buildings.png",
    "resources/textures/12_nebula_spritesheet.png"};

Texture2D TileController::textures[NUMBER_OF_TEXTURES];

void TileController::start() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(TileController::textureUrls[i]);
  }
}

void TileController::draw(Tile tile, Vector2 position, Texture texture) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, WHITE);
}

void TileController::stop() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
}
