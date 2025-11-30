#pragma once
#include "schedule.hpp"
#include "timer.hpp"
#include <functional>
#include <list>

class ScheduleService {
  static std::list<Schedule*> schedules;

public:
  // initialize
  static void start(); 
  // do fun once after interval in seconds
  static Schedule *once(VoidFunction fun, double interval);
  // repeat fun every interval in seconds.
  static Schedule *repeat(VoidFunction fun, double interval);
  // do once or repeat fun
  static void update();
  // free resources
  static void stop();  
};
