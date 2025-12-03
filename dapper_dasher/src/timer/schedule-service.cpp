#include "timer/schedule-service.hpp"

std::list<Schedule *> ScheduleService::schedules;

void ScheduleService::start() {}

Schedule *ScheduleService::once(VoidFunction fun, double interval) {
  Schedule *schedule = new Schedule();
  schedule->fun = fun;
  schedule->timer = new Timer{interval};
  schedule->timer->start();
  schedule->isRepetable = false;
  schedule->isExecuted = false;
  ScheduleService::schedules.push_front(schedule);
  return schedule;
}

Schedule *ScheduleService::repeat(VoidFunction fun, double interval) {
  Schedule *schedule = ScheduleService::once(fun, interval);
  schedule->isRepetable = true;
  return schedule;
}

void ScheduleService::update() {
  for (Schedule *schedule : ScheduleService::schedules) {
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

void ScheduleService::stop() {
  for (Schedule *schedule : ScheduleService::schedules) {
    delete schedule->timer;
    delete schedule;
  }
  ScheduleService::schedules.clear();
}
