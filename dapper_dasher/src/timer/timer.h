#pragma once

#include "raylib.h"

namespace game {
// Simple timer.
class Timer {
  double startTime;
  double endTime;

public:
  Timer(double endTime) {
    startTime = 0;
    this->endTime = endTime;
  }

  void start() { startTime = GetTime(); }

  bool isActive() { return startTime != 0 && elapsed() <= endTime; }

  double elapsed() { return GetTime() - startTime; }
};
} // namespace game
