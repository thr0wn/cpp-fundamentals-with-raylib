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
  _collisionGeometry.setOriginType(GEOMETRY_ORIGIN_CENTER);
  _collisionGeometry.setOrigin(
      Vector2{_tile.getDestiny().width / 2, _tile.getDestiny().height / 2});
  _collisionGeometry.setEnabled(false);

  // position and zoom
  float zoom = 2; // todo: move it to config
  Vector2 halfScreen =
      Vector2{config::WINDOW_WIDTH / 2.0f, config::WINDOW_HEIGHT / 2.0f};
  _player.setPosition(Vector2Scale(halfScreen, 1.0f / zoom));

  // tile
  _tileAnimation.setTimer(&_animationTimer);
  _tile.setAnimation(&_tileAnimation);
  _tile.setTexture(
      _textureLoader->getTextures()[GAME_TEXTURE_CHARACTER_KNIGHT_IDLE]);
  _animationTimer.start();

  // camera
  vector::copy(_player.getPosition(), _camera.target);
  vector::copy(halfScreen, _camera.offset);
  _camera.zoom = zoom;

  // player
  _player.addChild(&_tile);
  _player.addChild(&_collisionGeometry);

  // node manager
  _nodeManager.addChild(&_player);

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
  _tile.setColor(_gameState->running() ? WHITE : GRAY);
  _nodeManager.render();
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
  _player.setPosition(Vector2Add(_player.getPosition(), _translate));
}

void Player::updateCamera() {
  vector::copy(_player.getWorldPosition(), _camera.target);
}

void Player::updateTile() {
  if (Vector2Length(_translate) > 0) {
    _tile.setTexture(
        _textureLoader->getTextures()[GAME_TEXTURE_CHARACTER_KNIGHT_RUN]);

    if (_translate.x > 0) {
      _tile.getSource().width = std::abs(_tile.getSource().width);
    } else if (_translate.x < 0) {
      _tile.getSource().width = -std::abs(_tile.getSource().width);
    }
  } else {
    _tile.setTexture(
        _textureLoader->getTextures()[GAME_TEXTURE_CHARACTER_KNIGHT_IDLE]);
  }
}

void Player::updateNode() { _nodeManager.update(); }

} // namespace game
