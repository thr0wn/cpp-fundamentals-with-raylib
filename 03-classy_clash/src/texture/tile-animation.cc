#include "texture/tile-animation.h"

namespace game {
TileAnimation::TileAnimation(const int &size)
    : _size(size){};
TileAnimation::TileAnimation(const int &size, const int &rowSize)
    : _size(size), _rowSize(rowSize){};

void TileAnimation::next() {
  _counter = std::fmod(_counter, _size);
  _position.y = std::floor(_counter / _rowSize);
  _position.x = std::fmod(_counter, _rowSize);
  _counter++;
}

const Vector2 &TileAnimation::position() const { return _position; };

const int &TileAnimation::size() const { return _size; };

const int &TileAnimation::rowSize() const { return _rowSize; };
}
