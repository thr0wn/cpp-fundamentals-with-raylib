#include "timer/timer.h"
#include "raylib.h"

namespace game {
Timer::Timer(double endTime) {
  _startTime = 0;
  this->_endTime = endTime;
}

void Timer::start() { _startTime = GetTime(); }

bool Timer::active() { return _startTime != 0 && elapsed() <= _endTime; }

double Timer::elapsed() { return GetTime() - _startTime; }
} // namespace game
