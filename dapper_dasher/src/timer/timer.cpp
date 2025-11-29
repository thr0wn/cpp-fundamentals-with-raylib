#pragma once
#include "raylib.h"
#include "timer.hpp"

Timer::Timer(double endTime) { this->endTime = endTime; }

void Timer::start() { startTime = GetTime(); }

bool Timer::isActive() { return startTime != 0 && elapsed() <= endTime; }

double Timer::elapsed() { return GetTime() - startTime; }
