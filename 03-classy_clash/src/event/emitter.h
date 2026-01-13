#pragma once
#include "event/event.h"
#include "event/listener.h"
#include "iostream"
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
typedef std::map<std::string, std::list<Listener>> Listeners;
class Emitter {
private:
  Listeners _listeners;

public:
  inline const static EmitOptions DEFAULT_EMIT_OPTIONS = {
      {"log", true}, {"before", false}, {"after", false}};

  ~Emitter();

  const Listeners &listeners() const;

  Listener on(const std::string &eventName, const ListenerFunction &function);
  void off(const Listener &listener);
  void emit(const Event &event);
  void emit(const Event &event, const EmitOptions &options);
};
} // namespace game
