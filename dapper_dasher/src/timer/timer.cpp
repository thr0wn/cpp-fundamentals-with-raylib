#include "timer/timer.hpp"
#include "raylib.h"

Timer::Timer(double endTime) {
  startTime = 0;
  this->endTime = endTime;
}

void Timer::start() {
  startTime = GetTime();
}

bool Timer::isActive() { return startTime != 0 && elapsed() <= endTime; }

double Timer::elapsed() { return GetTime() - startTime; }
