#include "background.hpp"

void Background::start() {
  setBackground(TEXTURE_FAR_BUILDING, &texture, &position);
  setBackground(TEXTURE_BACK_BUILDING, &textureMid, &positionMid);
  setBackground(TEXTURE_NEAR_BUILDING, &textureNear, &positionNear);
}

void Background::update() {
  updateTexture(texture, &position, velocity);
  updateTexture(textureMid, &positionMid, velocityMid);
  updateTexture(textureNear, &positionNear, velocityNear);
}

void Background::render() {
  renderTexture(texture, position, velocity);
  renderTexture(textureMid, positionMid, velocityMid);
  renderTexture(textureNear, positionNear, velocityNear);  
}

void Background::stop() {}

void Background::setBackground(GameTexture gameTexture, Texture2D *texture,
                               Vector2 *position) {
  *texture = TileService::textures[gameTexture];
  position->x = 0;
  position->y = 0;
}

void Background::updateTexture(Texture2D texture, Vector2 *position,
                                float velocity) {
  if (position->x <= -3.0f * texture.width) {
    position->x = 0;
  }
  position->x += velocity * GetFrameTime();
}

void Background::renderTexture(Texture2D texture, Vector2 position,
                                float velocity) {
  Color color = GameService::isStartUI() ? GRAY : WHITE;
  Vector2 secondPosition = position;
  secondPosition.x += 3.0f * texture.width;
  DrawTextureEx(texture, position, 0, 3.0f, color);
  DrawTextureEx(texture, secondPosition, 0, 3.0f, color);  
}
