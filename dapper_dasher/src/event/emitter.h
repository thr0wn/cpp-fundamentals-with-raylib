#pragma once
#include "event/event.h"
#include "event/listener.h"
#include <functional>
#include <list>
#include <map>
#include <string>
#include <stdexcept>

namespace game {
class Emitter {
public:
  std::map<std::string, std::list<Listener>> listeners;  
  void on(std::string eventName, Listener listener);
  void off(std::string eventName, Listener listener);
  void emit(Event event);
};
} // namespace game
