#include "tile/tile.h"

namespace game {
Texture2D &Tile::texture() { return _texture; };
const Texture2D &Tile::texture() const { return _texture; };

TileAnimation::TileAnimation(const int &spriteTotal)
    : _spriteTotal(spriteTotal){};
TileAnimation::TileAnimation(const int &spriteTotal, const int &spriteRowSize)
    : _spriteTotal(spriteTotal), _spriteRowSize(spriteRowSize){};

void TileAnimation::next() {
  _counter = std::fmod(_counter, _spriteTotal);
  _sprite.y = std::floor(_counter / _spriteRowSize);
  _sprite.x = std::fmod(_counter, _spriteRowSize);
  _counter++;
}

Vector2 &TileAnimation::sprite() { return _sprite; };
const Vector2 &TileAnimation::sprite() const { return _sprite; };

int &TileAnimation::spriteTotal() { return _spriteTotal; };
const int &TileAnimation::spriteTotal() const { return _spriteTotal; };

int &TileAnimation::spriteRowSize() { return _spriteRowSize; };
const int &TileAnimation::spriteRowSize() const { return _spriteRowSize; };
} // namespace game
