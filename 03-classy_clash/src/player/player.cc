#include "player/player.h"

namespace game {
Player::Player() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/restart", [this](Event event) { onRestart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Player::onInit() {
  Rectangle collisionRectangle{0, 0, 0.5f * config::PLAYER_TILE_WIDTH,
                                  0.5f * config::PLAYER_TILE_HEIGHT};
  _player.collisionGeometry().pivot() = GEOMETRY_PIVOT_CENTER;
  _player.collisionGeometry().raw() = collisionRectangle;

  _player.center().x = _tile.destiny().width/2;
  _player.center().y = _tile.destiny().height/2;

  _player.position() =
      Vector2{config::WINDOW_WIDTH / 2 - _tile.destiny().width / 2,
              config::WINDOW_HEIGHT - _tile.destiny().height};

  _animationTimer.start();

  _log->info("(player) Initialized.");
};

void Player::onRestart() {
  onInit();
  _log->info("(player) Restarted.");
}

void Player::onUpdate() {
  if (!_gameState->running()) {
    return;
  }

  if (IsKeyDown(KEY_SPACE) && !jumping()) {
    _velocity = _jumpVelocity;
  } else {
    _velocity += _gravity * GetFrameTime();
  }

  _player.position().y += _velocity * GetFrameTime();

  // y borders
  if (_player.position().y < 0) {
    _player.position().y = 0;
  }
  if (_player.position().y > (config::WINDOW_HEIGHT - _tile.destiny().height)) {
    _player.position().y = config::WINDOW_HEIGHT - _tile.destiny().height;
  }

  if (!_animationTimer.active()) {
    if (!jumping()) {
      _tile.source().x = _tileAnimation.tile().x * _tile.source().width;
      _tileAnimation.next();
    }
    _animationTimer.start();
  }

  _player.update();

  _tile.destiny().x = _player.position().x;  
  _tile.destiny().y = _player.position().y;
}

void Player::onRender() {
  if (!_gameState->started()) {
    return;
  }
  _tile.color() = _gameState->running() ? WHITE : GRAY;
  _tile.render();
}

bool Player::jumping() {
  return _player.position().y <
         (config::WINDOW_HEIGHT - _tile.destiny().height);
}
} // namespace game
