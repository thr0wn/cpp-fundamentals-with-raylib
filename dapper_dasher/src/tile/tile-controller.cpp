#include "tile-controller.hpp"
#include "raylib.h"
#include "tile.hpp"

Texture2D TileController::textures[NUMBER_OF_TEXTURES];

void TileController::start() {
  textures[TEXTURE_SCARFY] = LoadTexture("resources/textures/scarfy.png");
}

void TileController::draw(Tile tile, Vector2 position, Texture texture) {
  Rectangle source = {(tile.x * tile.width), (tile.x * tile.height), tile.width, tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, WHITE);
}
