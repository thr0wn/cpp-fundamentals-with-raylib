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
const Texture2D Tile::texture() const { return _texture; };

Color &Tile::color() { return _color; };
const Color &Tile::color() const { return _color; };

TileAnimation *&Tile::animation() { return _animation; };
const TileAnimation *const Tile::animation() const { return _animation; };

void Tile::update() {
  Node2D::update();
  _destiny.x = position().x;
  _destiny.y = position().y;

  if (_animation) {
    _source.x = _animation->frame().x * _source.width;
    _source.y = _animation->frame().y * _source.height;
    _animation->update();
  }
}

void Tile::render() const {
  Node2D::render();  
  DrawTexturePro(_texture, _source, _destiny, origin(), rotation(), _color);
}
} // namespace game
