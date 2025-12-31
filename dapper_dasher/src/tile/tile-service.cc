#include "tile/tile-service.h"

namespace game {
TileService::TileService() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/deinit",
                  [this](Event event) { onDeinit(); });
};

void TileService::onInit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(textureUrls[i]);
  }
  gameEmitter->emit({"log/info",std::string( "(tile-service) Loaded textures.")});    
}

void TileService::onDeinit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
  gameEmitter->emit({"log/info",std::string( "(tile-service) Unloaded textures.")});      
}

void TileService::draw(Texture texture, Tile tile, Vector2 position,
                       Color color) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, color);
}

std::unique_ptr<TileService> tileService;
} // namespace game
