#pragma once
#include "game/game-node.hpp"
#include "log/log-service.hpp"
#include "timer/schedule.hpp"
#include "timer/timer.hpp"
#include <functional>
#include <list>

namespace game {
class ScheduleService : public GameNode {
private:
  std::list<Schedule *> schedules;

public:
  // initialize
  void start() override;
  // do fun once after interval in seconds
  Schedule *once(VoidFunction fun, double interval);
  // repeat fun every interval in seconds.
  Schedule *repeat(VoidFunction fun, double interval);
  // do once or repeat fun
  void update() override;
  // free resources
  void stop() override;
};

extern ScheduleService scheduleService;
} // namespace game
