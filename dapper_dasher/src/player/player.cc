#include "player/player.h"

namespace game {
Player::Player() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/restart", [this](Event event) { onRestart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render", [this](Event event) { onRender(); });
};

void Player::onInit() {
  Rectangle collisionRectangle = {0, 0, 0.5f * config::PLAYER_TILE_WIDTH,
                                  0.5f * config::PLAYER_TILE_HEIGHT};
  _player.collisionGeometry().pivot() = GEOMETRY_PIVOT_CENTER;
  _player.collisionGeometry().raw() = collisionRectangle;

  _player.tile().width = config::PLAYER_TILE_WIDTH;
  _player.tile().height = config::PLAYER_TILE_HEIGHT;
  _player.tile().x = 0;
  _player.tile().y = 0;
  _player.tile().texture() = _textureLoader->textures()[TEXTURE_SCARFY];

  _player.position() =
      Vector2{config::WINDOW_WIDTH / 2 - _player.tile().width / 2,
              config::WINDOW_HEIGHT - _player.tile().height};
  _log->info("(player) Player initialized.");
};

void Player::onRestart() {
  onInit();
  _log->info("(player) Player restarted.");
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
  if (_player.position().y > (config::WINDOW_HEIGHT - _player.tile().height)) {
    _player.position().y = config::WINDOW_HEIGHT - _player.tile().height;
  }

  if (!_animationTimer.active()) {
    if (!jumping()) {
      _player.tile().x = _tileAnimation.sprite().x;
      _tileAnimation.next();
    }
    _animationTimer.start();
  }

  _player.update();

  if (_player.checkCollision(_nebula->nebula())) {
    _gameState->setGameOver();
  }
}

void Player::onRender() {
  if (!_gameState->started()) {
    return;
  }
  _player.color() = _gameState->running() ? WHITE : GRAY;
  _player.render();
}

bool Player::jumping() {
  return _player.position().y < (config::WINDOW_HEIGHT - _player.tile().height);
}
} // namespace game
