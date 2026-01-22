#pragma once
#include "raylib.h"
#include "texture/tile-animation.h"
#include <map>

namespace game {
class Tile {
private:
  Rectangle _source;
  Rectangle _destiny;
  Texture2D *_texture;
  Vector2 _origin = Vector2{0};
  Vector2 _position = Vector2{0};  
  float _rotation = 0;  
  Color _color = WHITE;
  TileAnimation *_animation;

public:
  Tile() = default;

  Tile(float width, float height);

  Rectangle &source();
  const Rectangle &source() const;

  Rectangle &destiny();
  const Rectangle &destiny() const;

  Texture2D *&texture();
  const Texture2D * const texture() const;

  Vector2 &origin();
  const Vector2 &origin() const;

  Vector2 &position();
  const Vector2 &position() const;
 
  float &rotation();
  const float &rotation() const;

  Color &color();
  const Color &color() const;

  TileAnimation *&animation();
  const TileAnimation * const animation() const;

  void update();

  void render() const;
};
} // namespace game
