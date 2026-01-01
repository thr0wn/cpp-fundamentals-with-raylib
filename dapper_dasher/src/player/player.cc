#include "player/player.h"

namespace game {
Player::Player() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/init:after", [this](Event event) { onAfterInit(); });
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
  player.position = Vector2{config::WINDOW_WIDTH / 2 - player.tile.width / 2,
                            config::WINDOW_HEIGHT - player.tile.height};

  scheduleService->repeat(
      [this] {
        if (!gameService->isRunning()) {
          return;
        }
        if (!isJumping()) {
          tileAnimation.sprite = std::fmod(
              ++tileAnimation.sprite,
              tileAnimation
                  .spriteTotal); // 6x1 spritesheet, but with only 60 sprites
          player.tile.x = tileAnimation.sprite;
        }
      },
      config::PLAYER_ANIMATION_TIME);
  gameEmitter->emit({"log/info", std::string("(player) Player initialized.")});
};

void Player::onAfterInit() {
  player.tile.loadTexture(TEXTURE_SCARFY);
}

void Player::onRestart() {
  onInit();
  gameEmitter->emit({"log/info", std::string("(player) Player restarted.")});
}

void Player::onUpdate() {
  if (!gameService->isRunning()) {
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
}

void Player::onRender() {
  if (!gameService->isStarted()) {
    return;
  }
  Color color = gameService->isPaused() ? GRAY : WHITE;
  player.tile.draw(player.position, color);
}

bool Player::isJumping() {
  return player.position.y < (config::WINDOW_HEIGHT - player.tile.height);
}
} // namespace game
