#pragma once
#include "raylib.h"
#include <map>

namespace game {
class Tile {
private:
  Rectangle _source;
  Rectangle _destiny;
  Texture2D _texture;
  Vector2 _origin;
  float _rotation = 0;  
  Color _color = WHITE;

public:
  Tile() = default;

  Tile(float width, float height);

  Rectangle &source();
  const Rectangle &source() const;

  Rectangle &destiny();
  const Rectangle &destiny() const;

  Texture2D &texture();
  const Texture2D &texture() const;

  Vector2 &origin();
  const Vector2 &origin() const;
  
  float &rotation();
  const float &rotation() const;

  Color &color();
  const Color &color() const;

  void render() const;
};
} // namespace game
