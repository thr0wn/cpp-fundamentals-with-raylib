#pragma once
#include "game/game-node.h"
#include <iostream>
#include <string>

namespace game {
class LogService : public game::GameNode {
private:  
  bool enabled = true;  
public:
  LogService();

  // Log messages directly to sdtout
  void log(std::string message);
  // Set enabled logs
  void setEnabled(bool enabled);
};
extern LogService logService;
} // namespace game
