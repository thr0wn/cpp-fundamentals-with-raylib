#pragma once
#include "game/game-node.h"
#include "log/log-service.h"
#include "timer/schedule.h"
#include "timer/timer.h"
#include <functional>
#include <list>

namespace game {
class ScheduleService : public GameNode {
private:
  std::list<Schedule *> schedules;

public:
  ScheduleService();
  // reinitialize  
  void restart() override;
  // do fun once after interval in seconds
  Schedule *once(VoidFunction fun, double interval);
  // repeat fun every interval in seconds.
  Schedule *repeat(VoidFunction fun, double interval);
  // do once or repeat fun
  void update() override;
  // free resources
  void stop() override;
};

extern ScheduleService *scheduleService;
} // namespace game
