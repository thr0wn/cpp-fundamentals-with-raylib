#include "../common.hpp"

// Simple timer.
Timer::Timer(double endTime) { this->endTime = endTime; }

// start the timer
void Timer::start() { startTime = GetTime(); }

bool Timer::isActive() { return startTime != 0 && elapsed() <= endTime; }

double Timer::elapsed() { return GetTime() - startTime; }
