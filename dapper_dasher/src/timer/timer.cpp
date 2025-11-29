#pragma once
#include "raylib.h"

// Simple timer.
class Timer {
  double startTime = 0;
  double endTime = 0;
  
public:
  // set the endTime in seconds  
  Timer(double endTime) {
    this->endTime = endTime;    
  }

  // start the timer  
  void start() {
    startTime = GetTime();
  }

  bool isActive() {
    return startTime != 0 && elapsed() <= endTime;
  }

  double elapsed() {
    return GetTime() - startTime;    
  }    
};
