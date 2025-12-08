#pragma once
#include "game/game-node.hpp"
#include <string>

namespace game {
class LogService : public game::GameNode {
public:
  void start() override;

  void log(std::string message);
};
extern LogService logService;
} // namespace game
