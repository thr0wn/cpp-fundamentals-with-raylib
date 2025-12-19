#include "event/emitter.h"

namespace game {

EmitOptions Emitter::DEFAULT_EMIT_OPTIONS = {{"log", true}};

Emitter::Emitter(std::string name) : name(name) {
  logService.log(fmt::format("({}) Constructor", name));
}

Emitter::~Emitter() {
  for (auto itMap = listeners.begin(); itMap != listeners.end();) {
    itMap->second.clear();
    itMap = listeners.erase(itMap);
  }
  logService.log(fmt::format("({}) Destructor", name));
}

void Emitter::on(std::string eventName, Listener listener) {
  listeners[eventName].push_back(listener);  
  logService.log(fmt::format("({}) Added: \"{}\" on \"{}\"", name,
                             listener.name, eventName));
};

void Emitter::off(std::string eventName, Listener listener) {
  auto itMap = listeners.find(eventName);
  if (itMap != listeners.end()) {
    itMap->second.remove_if([listener](auto p) { return p.name == listener.name; });

    if (itMap->second.empty()) {
      listeners.erase(itMap);
    }
  }
  logService.log(fmt::format("({}) Removed: \"{}\" on \"{}\"", name,
                             listener.name, eventName));
};

void Emitter::emit(Event event) { emit(event, DEFAULT_EMIT_OPTIONS); };

void Emitter::emit(Event event, EmitOptions options) {
  try {
    EmitOptions finalOptions = options;
    finalOptions.merge(DEFAULT_EMIT_OPTIONS);
    bool shouldLog = std::any_cast<bool>(finalOptions["log"]);
    logService.setEnabled(shouldLog);
    logService.log(fmt::format("({}) Emitting: \"{}\"", name, event.name));
    auto it = listeners.find(event.name);
    if (it != listeners.end()) {
      auto listenersList = it->second;
      for (auto listener : listenersList) {
        logService.log(
            fmt::format("({}) Starting: \"{}\"", name, listener.name));
        listener.function(event);
        logService.log(
            fmt::format("({}) Ending: \"{}\"", name, listener.name));
      }
    }
    logService.log(fmt::format("({}) Emitted: \"{}\"", name, event.name));
    logService.setEnabled(true);
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};
} // namespace game
