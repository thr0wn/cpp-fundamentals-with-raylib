#pragma once
#include "event/event.h"
#include <cstdint>
#include <functional>
#include <string>

namespace game {
using ListenerFunction = std::function<void(const Event &)>;
class Listener {
public:
  static std::uint32_t idCounter;
  std::uint32_t id;
  std::string eventName;
  ListenerFunction function;
  Listener(std::string eventName, ListenerFunction function);
};
} // namespace game
