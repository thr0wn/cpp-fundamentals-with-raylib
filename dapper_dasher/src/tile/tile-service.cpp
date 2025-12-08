#include "tile/tile-service.hpp"

namespace game {
TileService::TileService() : GameNode("tile-service"){};

void TileService::start() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    *textures[i] = LoadTexture(textureUrls[i]);
  }
}

void TileService::draw(Texture texture, Tile tile, Vector2 position,
                       Color color) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, color);
}

void TileService::stop() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(*textures[i]);
  }
}

TileService *tileService;
} // namespace game
