#pragma once
#include "event/event.h"
#include "event/listener.h"
#include "log/log-service.h"
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
  void on(std::string eventName, Listener listener);
  void off(std::string eventName, Listener listener);
  void emit(Event event);
  void emit(Event event, EmitOptions options);
};
} // namespace game
