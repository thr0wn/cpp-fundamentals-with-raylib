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
  extern std::unique_ptr<LogService> logService;
} // namespace game
