#include "world/world.h"

namespace game {
World::World() {
  _emitter->on("game/init:after", [this](Event event) { onAfterInit(); });
  _emitter->on("game/render2d", [this](Event event) { onRender2d(); });
}

void World::onAfterInit() {
  _texture = _textureLoader->getTextures()[GAME_TEXTURE_WORLD_FOREST];
  _log->info("(world) Initialized.");
}

void World::onRender2d() {
  if (!_gameState->started()) {
    return;
  }
  _color = _gameState->paused() ? GRAY : WHITE;
  //DrawTextureEx(_texture, _position, 0, 1.0f, _color);
}

} // namespace game
