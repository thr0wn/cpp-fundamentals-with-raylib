#include "texture/tile-animation.h"

namespace game {
TileAnimation::TileAnimation(const int &size) : _size(size){};
TileAnimation::TileAnimation(const int &size, const int &rowSize)
    : _size(size), _rowSize(rowSize){};

Timer *&TileAnimation::timer() { return _timer; }
const Timer * const TileAnimation::timer() const { return _timer; }

const Vector2 &TileAnimation::frame() const { return _frame; };

const int &TileAnimation::size() const { return _size; };

const int &TileAnimation::rowSize() const { return _rowSize; };

void TileAnimation::update() {
  if (_timer && !_timer->active()) {
    _counter = std::fmod(_counter, _size);
    _frame.y = std::floor(_counter / _rowSize);
    _frame.x = std::fmod(_counter, _rowSize);
    _counter++;

    _timer->start();    
  }
}

} // namespace game
