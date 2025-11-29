#pragma once

// Simple timer.
class Timer {
  double startTime = 0;
  double endTime = 0;

public:
  // set the endTime in seconds  
  Timer(double endTime);
  // start the timer  
  void start();
  bool isActive();
  double elapsed();    
};
