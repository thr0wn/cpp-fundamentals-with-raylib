#pragma once
#include "timer/schedule.hpp"
#include "timer/timer.hpp"
#include <functional>
#include <list>

namespace scheduleService {
  // initialize
  void start(); 
  // do fun once after interval in seconds
  Schedule *once(VoidFunction fun, double interval);
  // repeat fun every interval in seconds.
  Schedule *repeat(VoidFunction fun, double interval);
  // do once or repeat fun
  void update();
  // free resources
  void stop();  
};
