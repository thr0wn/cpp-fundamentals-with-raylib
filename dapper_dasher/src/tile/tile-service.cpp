#include "tile/tile-service.hpp"

namespace tileService {
const char *textureUrls[] = {"resources/textures/scarfy.png",
                             "resources/textures/far-buildings.png",
                             "resources/textures/back-buildings.png",
                             "resources/textures/foreground.png",
                             "resources/textures/12_nebula_spritesheet.png"};

Texture2D textures[NUMBER_OF_TEXTURES];

void start() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(textureUrls[i]);
  }
}

  void draw(Texture texture, Tile tile, Vector2 position, Color color) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(texture, source, destiny, origin, 0.0f, color);
}

void stop() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
}
} // namespace tileService
