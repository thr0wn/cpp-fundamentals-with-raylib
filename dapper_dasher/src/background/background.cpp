#include "background.hpp"

void Background::start() {
  setBackground(TEXTURE_FAR_BUILDING, &texture, &position);
  setBackground(TEXTURE_BACK_BUILDING, &textureMid, &positionMid);
  setBackground(TEXTURE_NEAR_BUILDING, &textureNear, &positionNear);
}

void Background::update() {}

void Background::render() {
  moveBackground(texture, &position, velocity);
  moveBackground(textureMid, &positionMid, velocityMid);
  moveBackground(textureNear, &positionNear, velocityNear);
}

void Background::stop() {}

void Background::setBackground(GameTexture gameTexture, Texture2D *texture,
                               Vector2 *position) {
  *texture = TileService::textures[gameTexture];
  position->x = 0;
  position->y = 0;
}

void Background::moveBackground(Texture2D texture, Vector2 *position, float velocity) {
  if (position->x <= -3.0f * texture.width) {
    position->x = 0;
  }
  position->x += velocity * GetFrameTime();
  Vector2 secondPosition = *position;
  secondPosition.x += 3.0f * texture.width;
  TileService::drawTexture(texture, *position, 3.0f);
  TileService::drawTexture(texture, secondPosition, 3.0f);
}
