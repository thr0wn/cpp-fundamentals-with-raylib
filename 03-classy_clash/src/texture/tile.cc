#include "texture/tile.h"

namespace game {

Tile::Tile(float width, float height) {
  Rectangle rect = {0, 0, width, height};
  _source = rect;
  _destiny = rect;
}

void Tile::setSource(const Rectangle &source) { _source = source; };
Rectangle &Tile::getSource() { return _source; };

void Tile::setDestiny(const Rectangle &destiny) { _destiny = destiny; };
Rectangle &Tile::getDestiny() { return _destiny; };

void Tile::setTexture(const Texture2D &texture) { _texture = texture; };
const Texture2D &Tile::getTexture() const { return _texture; };

void Tile::setColor(const Color &color) { _color = color; };
const Color &Tile::getColor() const { return _color; };

void Tile::setAnimation(TileAnimation *animation) { _animation = animation; };
TileAnimation *Tile::getAnimation() const { return _animation; };

void Tile::update() {
  Node2D::update();
  _destiny.x = _worldPosition.x;
  _destiny.y = _worldPosition.y;

  if (_animation) {
    _source.x = _animation->getFrame().x * _source.width;
    _source.y = _animation->getFrame().y * _source.height;
    _animation->update();
  }
}

void Tile::render() {
  Node2D::render();
  DrawTexturePro(_texture, _source, _destiny, _origin, _worldRotation, _color);
}
} // namespace game
