#include "timer/schedule-service.hpp"

namespace scheduleService {
namespace {
std::list<Schedule *> schedules;
}
void start() {}

Schedule *once(VoidFunction fun, double interval) {
  Schedule *schedule = new Schedule();
  schedule->fun = fun;
  schedule->timer = new Timer{interval};
  schedule->timer->start();
  schedule->isRepetable = false;
  schedule->isExecuted = false;
  schedules.push_front(schedule);
  return schedule;
}

Schedule *repeat(VoidFunction fun, double interval) {
  Schedule *schedule = once(fun, interval);
  schedule->isRepetable = true;
  return schedule;
}

void update() {
  for (Schedule *schedule : schedules) {
    if (!schedule->timer->isActive()) {
      if (!schedule->isExecuted && !schedule->isRepetable) {
        schedule->fun();
        schedule->isExecuted = true;
      }
      if (schedule->isRepetable) {
        schedule->fun();
        schedule->timer->start();
      }
    }
  }
}

void stop() {
  for (Schedule *schedule : schedules) {
    delete schedule->timer;
    delete schedule;
  }
  schedules.clear();
}
} // namespace scheduleService
