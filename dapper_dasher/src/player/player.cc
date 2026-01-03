#include "player/player.h"

namespace game {
Player::Player() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
};

void Player::onInit() {
  // tile related properties
  player.tile.width = config::PLAYER_TILE_WIDTH;
  player.tile.height = config::PLAYER_TILE_HEIGHT;
  player.tile.x = 0;
  player.tile.y = 0;
  player.tile.setTexture(textureLoader->textures[TEXTURE_SCARFY]);
  player.position = Vector2{config::WINDOW_WIDTH / 2 - player.tile.width / 2,
                            config::WINDOW_HEIGHT - player.tile.height};
  log->info("(player) Player initialized.");
};

void Player::onRestart() {
  onInit();
  log->info("(player) Player restarted.");
}

void Player::onUpdate() {
  if (!gameState->isRunning()) {
    return;
  }

  if (IsKeyDown(KEY_SPACE) && !isJumping()) {
    velocity = jumpVelocity;
  } else {
    velocity += gravity * GetFrameTime();
  }

  player.position.y += velocity * GetFrameTime();

  // y borders
  if (player.position.y < 0) {
    player.position.y = 0;
  }
  if (player.position.y > (config::WINDOW_HEIGHT - player.tile.height)) {
    player.position.y = config::WINDOW_HEIGHT - player.tile.height;
  }

  if(!animationTimer.isActive()) {
    if (!isJumping()) {
      tileAnimation.sprite = std::fmod(
          ++tileAnimation.sprite,
          tileAnimation
              .spriteTotal); // 6x1 spritesheet, but with only 60 sprites
      player.tile.x = tileAnimation.sprite;
    }
    animationTimer.start();
  }
}

void Player::onRender() {
  if (!gameState->isStarted()) {
    return;
  }
  Color color = gameState->isPaused() ? GRAY : WHITE;
  player.tile.draw(player.position, color);
}

bool Player::isJumping() {
  return player.position.y < (config::WINDOW_HEIGHT - player.tile.height);
}
} // namespace game
