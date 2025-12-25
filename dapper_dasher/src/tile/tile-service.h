#pragma once
#include "game/game-node.h"
#include "log/log-service.h"
#include "tile/tile.h"
#include <memory>

namespace game {
class TileService : public GameNode {
public:
  TileService();

  const char *textureUrls[NUMBER_OF_TEXTURES] = {
      "resources/textures/scarfy.png", "resources/textures/far-buildings.png",
      "resources/textures/back-buildings.png",
      "resources/textures/foreground.png",
      "resources/textures/12_nebula_spritesheet.png"};
  Texture2D textures[NUMBER_OF_TEXTURES];

  void start() override;
  void stop() override;
  void draw(Texture texture, Tile tile, Vector2 position, Color color);
};
  extern std::unique_ptr<TileService> tileService;
} // namespace game
