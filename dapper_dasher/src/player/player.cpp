#include "player.hpp"
#include "game-service.hpp"

void Player::start() {
  // tile related properties
  tile.width = PLAYER_TILE_WIDTH;
  tile.height = PLAYER_TILE_HEIGHT;
  tile.x = 0;
  tile.y = 0;
  position =
      Vector2{windowWidth / 2 - tile.width / 2, windowHeight - tile.height};

  ScheduleService::repeat(
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
  if (position.y > (windowHeight - tile.height)) {
    position.y = windowHeight - tile.height;
  }
}

void Player::render() {
  GameState gameState = GameService::getGameState();
  if (!gameState.started) {
    return;
  }
  TileService::draw(TileService::textures[TEXTURE_SCARFY], tile, position);
}

void Player::stop(){};

bool Player::isJumping() { return position.y < (windowHeight - tile.height); }
