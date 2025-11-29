#pragma once

// Simple timer.
class Timer {
  double startTime;
  double endTime;

public:
  Timer(double endTIme);  
  // Start the timer
  void start();
  // Return true if elapsed time is less than endTime
  bool isActive();
  // Elapsed time since start  
  double elapsed();    
};
