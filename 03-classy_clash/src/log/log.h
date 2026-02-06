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

  void setEnabled(bool enabled);
  bool getEnabled() const;  
};
} // namespace game
