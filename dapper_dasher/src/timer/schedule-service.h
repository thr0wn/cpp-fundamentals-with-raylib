#pragma once
#include "game/game-emitter.h"
#include "timer/schedule.h"
#include "timer/timer.h"
#include <functional>
#include <list>
#include <memory>

namespace game {
class ScheduleService {
private:
  std::list<Schedule *> schedules;

public:
  ScheduleService();
  // reinitialize  
  void onRestart();
  // do fun once after interval in seconds
  Schedule *once(VoidFunction fun, double interval);
  // repeat fun every interval in seconds.
  Schedule *repeat(VoidFunction fun, double interval);
  // do once or repeat fun
  void onUpdate();
  // free resources
  void onDeinit();
};

  extern std::unique_ptr<ScheduleService> scheduleService;
} // namespace game
