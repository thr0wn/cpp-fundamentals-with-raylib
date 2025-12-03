#include "tile/tile-service.hpp"

const char *TileService::textureUrls[] = {
    "resources/textures/scarfy.png", "resources/textures/far-buildings.png",
    "resources/textures/back-buildings.png",
    "resources/textures/foreground.png",
    "resources/textures/12_nebula_spritesheet.png"};

Texture2D TileService::textures[NUMBER_OF_TEXTURES];

void TileService::start() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(TileService::textureUrls[i]);
  }
}

void TileService::draw(Texture texture, Tile tile, Vector2 position) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, WHITE);
}

void TileService::stop() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
}
