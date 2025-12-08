#include "player/player.hpp"

namespace game {
  Player::Player(): GameNode2D("player") {};
  
  void Player::start() {
    // tile related properties
    tile.width = PLAYER_TILE_WIDTH;
    tile.height = PLAYER_TILE_HEIGHT;
    tile.x = 0;
    tile.y = 0;
    position = Vector2{config::WINDOW_WIDTH / 2 - tile.width / 2,
                       config::WINDOW_HEIGHT - tile.height};

    scheduleService->repeat(
                            [this] {
                            if (!isJumping()) {
                              tileAnimation.sprite++;
                              tileAnimation.sprite = std::fmod(
                                                               tileAnimation.sprite,
                                                               tileAnimation
                                                               .spriteTotal); // 6x1 spritesheet, but with only 60 sprites
                              tile.x = tileAnimation.sprite;
                            }
                            },
                            PLAYER_ANIMATION_TIME);
  };

  void Player::update() {
    if (IsKeyDown(KEY_SPACE) && !isJumping()) {
      velocity = jumpVelocity;
    } else {
      velocity += gravity * GetFrameTime();
    }

    position.y += velocity * GetFrameTime();

    // y borders
    if (position.y < 0) {
      position.y = 0;
    }
    if (position.y > (config::WINDOW_HEIGHT - tile.height)) {
      position.y = config::WINDOW_HEIGHT - tile.height;
    }
  }

  void Player::render() {
    if (!gameService->isStarted()) {
      return;
    }
    Color color = gameService->isPaused() ? GRAY : WHITE;
    tileService->draw(tileService->textures[TEXTURE_SCARFY], tile, position,
                      color);
  }

  void Player::stop(){};

  bool Player::isJumping() {
    return position.y < (config::WINDOW_HEIGHT - tile.height);
  }
} // namespace game
