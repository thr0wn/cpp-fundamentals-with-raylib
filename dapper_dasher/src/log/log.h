#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"
#include <iostream>
#include <string>
#include <fmt/format.h>

namespace game {
class Log {
private:
  bool _enabled = true;
  Emitter *_emitter = AsyncPointer::get<Emitter>();  
public:
  void info(const std::string &message);

  bool &enabled();
  const bool &enabled() const;  
};
} // namespace game
