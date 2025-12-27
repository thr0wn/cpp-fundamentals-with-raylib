#include "timer/schedule-service.h"

namespace game {
ScheduleService::ScheduleService() {
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/deinit", [this](Event event) { onDeinit(); });
};

void ScheduleService::onRestart() { onDeinit(); };

Schedule *ScheduleService::once(VoidFunction fun, double interval) {
  Schedule *schedule = new Schedule();
  schedule->fun = fun;
  schedule->timer = new Timer{interval};
  schedule->timer->start();
  schedule->isRepetable = false;
  schedule->isExecuted = false;
  schedules.push_front(schedule);
  return schedule;
}

Schedule *ScheduleService::repeat(VoidFunction fun, double interval) {
  Schedule *schedule = once(fun, interval);
  schedule->isRepetable = true;
  return schedule;
}

void ScheduleService::onUpdate() {
  if (!gameService->isRunning()) {
    return;
  }
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

void ScheduleService::onDeinit() {
  for (Schedule *schedule : schedules) {
    delete schedule->timer;
    delete schedule;
  }
  schedules.clear();
}
std::unique_ptr<ScheduleService> scheduleService;
} // namespace game
