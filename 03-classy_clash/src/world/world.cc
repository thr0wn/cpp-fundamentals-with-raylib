#include "world/world.h"

namespace game {
World::World() {
  _emitter->on("game/init:after", [this](Event event) { onAfterInit(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
}

void World::onAfterInit() {
  _texture = _textureLoader->textures()[GAME_TEXTURE_WORLD];
  _log->info("(world) Initialized.");  
}

void World::onRender() {
  if (!_gameState->started()) {
    return;
  }
  DrawTexture(_texture, 0, 0, WHITE);
}
} // namespace game
