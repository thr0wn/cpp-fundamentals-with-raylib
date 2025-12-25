#pragma once
#include "event/event.h"
#include <functional>
#include <string>

namespace game {
typedef std::function<void(const Event&)> ListenerFunction;
class Listener {
public:
  static uint idCounter;  
  uint id;
  std::string eventName;
  ListenerFunction function;
  Listener(std::string eventName, ListenerFunction function);
};
} // namespace game
