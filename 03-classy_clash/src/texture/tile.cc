#include "texture/tile.h"

namespace game {

Tile::Tile(float width, float height) {
  Rectangle rect = {0, 0, width, height};
  _source = rect;  
  _destiny = rect;  
  }

Rectangle &Tile::source() { return _source; };
const Rectangle &Tile::source() const { return _source; };

Rectangle &Tile::destiny() { return _destiny; };
const Rectangle &Tile::destiny() const { return _destiny; };

Texture2D &Tile::texture() { return _texture; };
const Texture2D &Tile::texture() const { return _texture; };

Vector2 &Tile::origin() { return _origin; };
const Vector2 &Tile::origin() const { return _origin; };

float &Tile::rotation() { return _rotation; };
const float &Tile::rotation() const { return _rotation; };

Color &Tile::color() { return _color; };
const Color &Tile::color() const { return _color; };

void Tile::render() const {
  DrawTexturePro(_texture, _source, _destiny, _origin, _rotation, _color);
}
} // namespace game
