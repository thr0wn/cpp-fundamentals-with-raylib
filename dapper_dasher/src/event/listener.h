#pragma once
#include "event/event.h"
#include <cstdint>
#include <functional>
#include <string>

namespace game {
using ListenerFunction = std::function<void(const Event &)>;
class Listener {
private:
  inline static std::uint32_t idCounter = 0;

public:
  std::uint32_t id;
  std::string eventName;
  ListenerFunction function;
  Listener(std::string eventName, ListenerFunction function)
      : eventName(eventName), function(function) {
    id = idCounter++;
  }
};
} // namespace game
