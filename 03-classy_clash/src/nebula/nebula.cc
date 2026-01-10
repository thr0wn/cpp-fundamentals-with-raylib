#include "nebula/nebula.h"

namespace game {
Nebula::Nebula() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/restart", [this](Event event) { onRestart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
}

void Nebula::onInit() {
  Rectangle collisionRectangle = {0, 0, 0.5f * config::NEBULA_TILE_WIDTH,
                                  0.5f * config::NEBULA_TILE_HEIGHT};
  _nebula.collisionGeometry().pivot() = GEOMETRY_PIVOT_CENTER;
  _nebula.collisionGeometry().raw() = collisionRectangle;

  _nebula.tile().width = config::NEBULA_TILE_WIDTH;
  _nebula.tile().height = config::NEBULA_TILE_HEIGHT;
  _nebula.tile().x = 0;
  _nebula.tile().y = 0;
  _nebula.tile().texture() = _textureLoader->textures()[TEXTURE_NEBULA];
  _nebula.position() = Vector2{config::WINDOW_WIDTH + _nebula.tile().width / 2,
                               config::WINDOW_HEIGHT - _nebula.tile().height};
  _log->info("(nebula) Nebula initialized.");
};

void Nebula::onRestart() {
  onInit();
  _log->info("(nebula) Nebula restarted.");
}

void Nebula::onUpdate() {
  if (!_gameState->running()) {
    return;
  }

  _nebula.position().x += _velocity * GetFrameTime();

  // // extremes
  if (_nebula.position().x < -_nebula.tile().width) {
    _nebula.position().x = config::WINDOW_WIDTH + _nebula.tile().width;
  }

  if (!_animationTimer.active()) {
    _nebula.tile().x = _tileAnimation.sprite().x;
    _nebula.tile().y = _tileAnimation.sprite().y;
    _tileAnimation.next();
    _animationTimer.start();
  }

  _nebula.update();
}

void Nebula::onRender() {
  if (!_gameState->started()) {
    return;
  }
  _nebula.color() = _gameState->running() ? WHITE : GRAY;
  _nebula.render();
}

const GameNode2D &Nebula::nebula() const { return _nebula; }
} // namespace game
