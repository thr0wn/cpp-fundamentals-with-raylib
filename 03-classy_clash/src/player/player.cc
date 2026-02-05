#include "player/player.h"

namespace game {
Player::Player() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/restart", [this](Event event) { onRestart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render2d", [this](Event event) { onRender2d(); });
};

const Camera2D &Player::camera() const { return _camera; };

void Player::onInit() {
  // collision
  _collisionGeometry.originType() = GEOMETRY_ORIGIN_CENTER;
  _collisionGeometry.origin().x = _tile.destiny().width / 2;
  _collisionGeometry.origin().y = _tile.destiny().height / 2;
  _collisionGeometry.enabled() = false;
  
  // position and zoom
  float zoom = 2; // todo: move it to config
  Vector2 halfScreen =
      Vector2{config::WINDOW_WIDTH / 2.0f, config::WINDOW_HEIGHT / 2.0f};
  vector::copy(Vector2Scale(halfScreen, 1.0f / zoom), _player.position());

  // tile
  _tileAnimation.timer() = &_animationTimer;
  _tile.animation() = &_tileAnimation;
  _tile.texture() =
      _textureLoader->textures()[GAME_TEXTURE_CHARACTER_KNIGHT_IDLE];
  _animationTimer.start();

  // camera
  vector::copy(_player.position(), _camera.target);
  vector::copy(halfScreen, _camera.offset);
  _camera.zoom = zoom;

  // player root node
  _player.addChild(&_tile);  
  _player.addChild(&_collisionGeometry);  

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

  updateTranslate();
  updateCamera();
  updateTile();
  updateNode();
}

void Player::onRender2d() {
  if (!_gameState->started()) {
    return;
  }
  _tile.color() = _gameState->running() ? WHITE : GRAY;
  _player.render();
}

void Player::updateTranslate() {
  _translate.x = 0;
  _translate.y = 0;

  if (IsKeyDown(KEY_A)) {
    _translate.x -= 1.0;
  } else if (IsKeyDown(KEY_D)) {
    _translate.x += 1.0;
  }
  if (IsKeyDown(KEY_W)) {
    _translate.y -= 1.0;
  } else if (IsKeyDown(KEY_S)) {
    _translate.y += 1.0;
  }

  _translate =
      Vector2Scale(Vector2Normalize(_translate), _velocity * GetFrameTime());
  vector::copy(Vector2Add(_player.position(), _translate), _player.position());
}

void Player::updateCamera() {
  vector::copy(_player.worldPosition(), _camera.target);
}

void Player::updateTile() {
  if (Vector2Length(_translate) > 0) {
    _tile.texture() =
        _textureLoader->textures()[GAME_TEXTURE_CHARACTER_KNIGHT_RUN];

    if (_translate.x > 0) {
      _tile.source().width = std::abs(_tile.source().width);
    } else if (_translate.x < 0) {
      _tile.source().width = -std::abs(_tile.source().width);
    }
  } else {
    _tile.texture() =
        _textureLoader->textures()[GAME_TEXTURE_CHARACTER_KNIGHT_IDLE];
  }
}

void Player::updateNode() { _player.update(); }

} // namespace game
