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
  _color = _gameState->paused() ? GRAY : WHITE;
  DrawTextureEx(_texture, _position, 0, 4.0f, _color);
}

Vector2 &World::position() { return _position; };
const Vector2 &World::position() const { return _position; };
} // namespace game
