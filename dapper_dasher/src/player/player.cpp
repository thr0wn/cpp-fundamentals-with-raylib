#include "player.hpp"
#include "schedule-service.hpp"

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
        tile.x++;
        tile.x = std::fmod(tile.x, PLAYER_TOTAL_TILES);        
      },
      PLAYER_ANIMATION_TIME);
};

void Player::update() {
  if (IsKeyDown(KEY_SPACE) && position.y == (windowHeight - tile.height)) {
    velocity = jumpVelocity;
  } else {
    velocity += gravity * GetFrameTime();
  }

  position.y += velocity * GetFrameTime();

  // extremes
  if (position.y < 0) {
    position.y = 0;
  }
  if (position.y > (windowHeight - tile.height)) {
    position.y = windowHeight - tile.height;
  }
}

void Player::render() {
  TileService::draw(TileService::textures[TEXTURE_SCARFY], tile, position);
}

void Player::stop(){};
