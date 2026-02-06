#include "texture/tile-animation.h"

namespace game {
TileAnimation::TileAnimation(int size) : _size(size){};
TileAnimation::TileAnimation(int size, int rowSize)
    : _size(size), _rowSize(rowSize){};

void TileAnimation::setTimer(Timer *timer) { _timer = timer; }
Timer *TileAnimation::getTimer() const { return _timer; }

const Vector2 &TileAnimation::getFrame() const { return _frame; };

int TileAnimation::getSize() const { return _size; };

int TileAnimation::getRowSize() const { return _rowSize; };

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
