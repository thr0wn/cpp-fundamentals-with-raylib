#pragma once
#include "event/event.h"
#include "event/listener.h"
#include <algorithm>
#include <fmt/format.h>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

namespace game {
typedef std::map<std::string, std::any> EmitOptions;
class Emitter {
public:
  static EmitOptions DEFAULT_EMIT_OPTIONS;

  std::map<std::string, std::list<Listener>> listeners;
  std::string name;
  Emitter(std::string name);
  ~Emitter();

  Listener on(std::string eventName, ListenerFunction function);
  void off(Listener listener);
  void emit(Event event);
  void emit(Event event, EmitOptions options);
};
} // namespace game
