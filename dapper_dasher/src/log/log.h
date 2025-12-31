#pragma once
#include "game/game-emitter.h"
#include <iostream>
#include <string>
#include <fmt/format.h>

namespace game {
class Log {
private:  
  bool enabled = true;  
public:
  Log();

  // Log messages directly to sdtout
  void info(std::string message);
  // Set enabled logs
  void setEnabled(bool enabled);
  // Check if enabled
  bool isEnabled();  
};
} // namespace game
