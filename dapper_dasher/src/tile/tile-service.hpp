#pragma once
#include "game/game-node.hpp"
#include "log/log-service.hpp"
#include "tile/tile.hpp"

namespace game {
class TileService : public GameNode {
public:  
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
extern TileService tileService;
} // namespace game
