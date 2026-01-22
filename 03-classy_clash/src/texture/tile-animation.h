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
  TileAnimation(const int &size);
  TileAnimation(const int &size, const int &rowSize);

  Timer *&timer();
  const Timer * const timer() const;

  const Vector2 &frame() const;

  const int &size() const;

  const int &rowSize() const;
  
  void update();
};
}
