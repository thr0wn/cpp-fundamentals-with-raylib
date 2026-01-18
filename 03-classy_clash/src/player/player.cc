#include "player/player.h"

namespace game {
Player::Player() {
  _emitter->on("game/init", [this](Event event) { onInit(); });
  _emitter->on("game/restart", [this](Event event) { onRestart(); });
  _emitter->on("game/update", [this](Event event) { onUpdate(); });
  _emitter->on("game/render2d", [this](Event event) { onRender2d(); });
};

void Player::onInit() {
  // collision
  Rectangle collisionRectangle{0, 0, 0.5f * config::PLAYER_TILE_WIDTH,
                               0.5f * config::PLAYER_TILE_HEIGHT};
  _player.collisionGeometry().pivot() = GEOMETRY_PIVOT_CENTER;
  _player.collisionGeometry().raw() = collisionRectangle;
  _player.collisionGeometry().origin().x = _idleTile.destiny().width / 2;
  _player.collisionGeometry().origin().y = _idleTile.destiny().height / 2;

  // position and zoom
  float zoom = 2; // todo: move it to config  
  Vector2 halfScreen = Vector2{config::WINDOW_WIDTH / 2.0f, config::WINDOW_HEIGHT / 2.0f};  
  vector::copy(Vector2Scale(halfScreen, 1.0f/zoom), _player.position());

  // tile
  _idleTile.texture() =
      _textureLoader->textures()[GAME_TEXTURE_CHARACTER_KNIGHT_IDLE];
  _idleAnimationTimer.start();

  // camera
  vector::copy(_player.position(), _camera.target);
  vector::copy(halfScreen, _camera.offset);
  _camera.zoom = zoom;

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

  updatePosition();
  updateCamera();
  updateTile();
}

void Player::onRender2d() {
  if (!_gameState->started()) {
    return;
  }
  _idleTile.color() = _gameState->running() ? WHITE : GRAY;
  _idleTile.render();
}

void Player::updatePosition() {
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
  vector::copy(_player.position(), _camera.target);
}

void Player::updateTile() {
  // tile move
  _idleTile.destiny().x = _player.position().x;
  _idleTile.destiny().y = _player.position().y;

  // tile animation  
  if (!_idleAnimationTimer.active()) {
    _idleTile.source().x =
        _idleTileAnimation.position().x * _idleTile.source().width;
    _idleTileAnimation.next();
    _idleAnimationTimer.start();
  }

  if (_translate.x >= 0) {
    _idleTile.source().width = std::abs(_idleTile.source().width);
  } else {
    _idleTile.source().width = -std::abs(_idleTile.source().width);    
  }
}

const Camera2D &Player::camera() const { return _camera; };

} // namespace game
