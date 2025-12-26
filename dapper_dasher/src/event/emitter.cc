#include "event/emitter.h"

namespace game {

EmitOptions Emitter::DEFAULT_EMIT_OPTIONS = {
    {"log", true}, {"before", true}, {"after", true}};

Emitter::Emitter(std::string name) : name(name) {
  logService->info(fmt::format("({}) Constructor", name));
}

Emitter::~Emitter() {
  for (auto itMap = listeners.begin(); itMap != listeners.end();) {
    itMap->second.clear();
    itMap = listeners.erase(itMap);
  }
  logService->info(fmt::format("({}) Destructor", name));
}

Listener Emitter::on(std::string eventName, ListenerFunction function) {
  Listener listener{eventName, function};
  listeners[eventName].push_back(listener);
  logService->info(
      fmt::format("({}) Added: listener on \"{}\"", name, eventName));
  return listener;
};

void Emitter::off(Listener listener) {
  auto itMap = listeners.find(listener.eventName);
  if (itMap != listeners.end()) {
    itMap->second.remove_if([listener](auto p) { return p.id == listener.id; });

    if (itMap->second.empty()) {
      listeners.erase(itMap);
    }
  }
  logService->info(fmt::format("({}) Removed: listener on \"{}\"", name,
                              listener.eventName));
};

void Emitter::emit(Event event) { emit(event, DEFAULT_EMIT_OPTIONS); };

void Emitter::emit(Event event, EmitOptions options) {
  try {
    EmitOptions finalOptions = DEFAULT_EMIT_OPTIONS;
    for (const auto &option : options) {
      finalOptions[option.first] = option.second;
    }
    bool previousLogIsEnabled = logService->isEnabled();    
    bool shouldLog = std::any_cast<bool>(finalOptions["log"]);
    bool shouldEmitBefore = std::any_cast<bool>(finalOptions["before"]);
    bool shouldEmitAfter = std::any_cast<bool>(finalOptions["after"]);
    if (shouldEmitBefore) {
      auto beforeEventName = event.name + ":before";
      Event beforeEvent{beforeEventName, event.values};
      emit(beforeEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
    logService->setEnabled(shouldLog);
    logService->info(fmt::format("({}) Emitting: \"{}\"", name, event.name));    
    auto it = listeners.find(event.name);
    if (it != listeners.end()) {
      auto listenersList = it->second;
      for (auto listener : listenersList) {
        listener.function(event);
      }
    }
    logService->info(fmt::format("({}) Emitted: \"{}\"", name, event.name));
    logService->setEnabled(previousLogIsEnabled);    
    if (shouldEmitAfter) {
      auto afterEventName = event.name + ":after";
      Event afterEvent{afterEventName, event.values};
      emit(afterEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};

void Emitter::emit(std::string eventName) {
  Event event{eventName, {}};
  emit(event);
};
} // namespace game
