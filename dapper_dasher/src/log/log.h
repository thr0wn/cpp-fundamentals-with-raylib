#pragma once
#include "event/emitter.h"
#include <fmt/format.h>
#include <iostream>
#include <string>

namespace game {
class Log {
private:
  bool enabled = true;

public:
  void info(std::string message) {
    if (enabled)
      std::cout << fmt::format("GAMEINFO: {}\n", message.data());
  }

  void setEnabled(bool enabled) { this->enabled = enabled; }
  bool isEnabled() { return enabled; }
};
} // namespace game
