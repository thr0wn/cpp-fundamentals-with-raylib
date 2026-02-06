#pragma once
#include "raylib.h"
#include "timer/timer.h"
#include <climits>
#include <cmath>

namespace game {
class TileAnimation {
private:
  int _counter = 0;
  Vector2 _frame;
  int _size{INT_MAX};
  int _rowSize{INT_MAX};
  Timer *_timer;  

public:
  TileAnimation(int size);
  TileAnimation(int size, int rowSize);

  void setTimer(Timer *timer);
  Timer * getTimer() const;

  const Vector2 &getFrame() const;

  int getSize() const;

  int getRowSize() const;

  void update();
};
}
