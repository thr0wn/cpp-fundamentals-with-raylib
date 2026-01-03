#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"
#include <iostream>
#include <string>
#include <fmt/format.h>

namespace game {
class Log {
private:
  bool enabled = true;
  Emitter *emitter = AsyncPointer::get<Emitter>();  
public:
  // Log messages directly to sdtout
  void info(std::string message);
  // Set enabled logs
  void setEnabled(bool enabled);
  // Check if enabled
  bool isEnabled();  
};
} // namespace game
