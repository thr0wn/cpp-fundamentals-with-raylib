#include "texture/tile.h"

namespace game {

Tile::Tile(const Rectangle &source) : _source(source), _destiny(source) {}

Rectangle &Tile::source() { return _source; };
const Rectangle &Tile::source() const { return _source; };

Rectangle &Tile::destiny() { return _destiny; };
const Rectangle &Tile::destiny() const { return _destiny; };

Texture2D &Tile::texture() { return _texture; };
const Texture2D &Tile::texture() const { return _texture; };

Color &Tile::color() { return _color; };
const Color &Tile::color() const { return _color; };

void Tile::render() const {
  Vector2 origin = {0, 0};
  DrawTexturePro(_texture, _source, _destiny, origin, 0.0f, _color);
}

TileAnimation::TileAnimation(const int &spriteTotal)
    : _tileTotal(spriteTotal){};
TileAnimation::TileAnimation(const int &spriteTotal, const int &spriteRowSize)
    : _tileTotal(spriteTotal), _tileRowSize(spriteRowSize){};

void TileAnimation::next() {
  _counter = std::fmod(_counter, _tileTotal);
  _tile.y = std::floor(_counter / _tileRowSize);
  _tile.x = std::fmod(_counter, _tileRowSize);
  _counter++;
}

Vector2 &TileAnimation::tile() { return _tile; };
const Vector2 &TileAnimation::tile() const { return _tile; };

int &TileAnimation::tileTotal() { return _tileTotal; };
const int &TileAnimation::tileTotal() const { return _tileTotal; };

int &TileAnimation::tileRowSize() { return _tileRowSize; };
const int &TileAnimation::tileRowSize() const { return _tileRowSize; };
} // namespace game
