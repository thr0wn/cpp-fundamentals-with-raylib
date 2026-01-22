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

Texture2D *&Tile::texture() { return _texture; };
const Texture2D * const Tile::texture() const { return _texture; };

Vector2 &Tile::origin() { return _origin; };
const Vector2 &Tile::origin() const { return _origin; };

Vector2 &Tile::position() { return _position; };
const Vector2 &Tile::position() const { return _position; };

float &Tile::rotation() { return _rotation; };
const float &Tile::rotation() const { return _rotation; };

Color &Tile::color() { return _color; };
const Color &Tile::color() const { return _color; };

TileAnimation *&Tile::animation() { return _animation; };
const TileAnimation *const Tile::animation() const { return _animation; };

void Tile::update() {
  _destiny.x = _position.x;
  _destiny.y = _position.y;

  if (_animation) {
    _source.x = _animation->frame().x * _source.width;
    _source.y = _animation->frame().y * _source.height;
    _animation->update();
  }
}

void Tile::render() const {
  if (_texture) {
    DrawTexturePro(*_texture, _source, _destiny, _origin, _rotation, _color);
  }
}
} // namespace game
