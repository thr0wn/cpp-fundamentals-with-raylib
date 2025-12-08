#pragma once
#include "timer/timer.hpp"
#include <functional>
#include <list>

namespace game {
typedef std::function<void(void)> VoidFunction;

class Schedule {
public:
  Timer *timer = NULL;
  VoidFunction fun;
  bool isExecuted;
  bool isRepetable;
};
} // namespace game
