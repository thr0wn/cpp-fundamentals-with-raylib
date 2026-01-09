#pragma once

namespace game {
// Simple timer.
class Timer {
private:  
  double _startTime;
  double _endTime;

public:
  Timer(double endTIme);
  // Start the timer
  void start();
  // Return true if elapsed time is less than endTime
  bool active();
  // Elapsed time since start
  double elapsed();
};
} // namespace game
