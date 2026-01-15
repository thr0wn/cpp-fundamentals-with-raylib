#pragma once
#include <iostream>
#include <string>
#include <fmt/format.h>

namespace game {
class Log {
private:
  bool _enabled = true;
public:
  void info(const std::string &message);

  bool &enabled();
  const bool &enabled() const;  
};
} // namespace game
