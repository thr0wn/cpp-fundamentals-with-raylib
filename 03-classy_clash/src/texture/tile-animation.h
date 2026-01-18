#pragma once
#include "raylib.h"
#include <climits>
#include <cmath>

namespace game {
class TileAnimation {
private:
  int _counter = 0;
  Vector2 _position;
  int _size{INT_MAX};
  int _rowSize{INT_MAX};

public:
  TileAnimation(const int &size);
  TileAnimation(const int &size, const int &rowSize);

  void next();

  const Vector2 &position() const;

  const int &size() const;

  const int &rowSize() const;
};
}
