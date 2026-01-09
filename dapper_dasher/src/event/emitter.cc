#include "event/emitter.h"

namespace game {

Emitter::~Emitter() {
  for (auto itMap = _listeners.begin(); itMap != _listeners.end();) {
    itMap->second.clear();
    itMap = _listeners.erase(itMap);
  }
}

Listeners &Emitter::listeners() { return _listeners; };
const Listeners &Emitter::listeners() const { return _listeners; };

Listener Emitter::on(const std::string &eventName,
                     const ListenerFunction &function) {
  Listener listener{eventName, function};
  _listeners[eventName].push_back(listener);
  return listener;
};

void Emitter::off(const Listener &listener) {
  auto itMap = _listeners.find(listener.eventName());
  if (itMap != _listeners.end()) {
    itMap->second.remove_if(
        [listener](auto p) { return p.id() == listener.id(); });

    if (itMap->second.empty()) {
      _listeners.erase(itMap);
    }
  }
};

void Emitter::emit(const Event &event) { emit(event, DEFAULT_EMIT_OPTIONS); };

void Emitter::emit(const Event &event, const EmitOptions &options) {
  try {
    EmitOptions finalOptions = DEFAULT_EMIT_OPTIONS;
    for (const auto &option : options) {
      finalOptions[option.first] = option.second;
    }
    bool shouldLog = std::any_cast<bool>(finalOptions["log"]);
    bool shouldEmitBefore = std::any_cast<bool>(finalOptions["before"]);
    bool shouldEmitAfter = std::any_cast<bool>(finalOptions["after"]);
    if (shouldEmitBefore) {
      auto beforeEventName = event.name() + ":before";
      decltype(event) beforeEvent{beforeEventName, event.value()};
      emit(beforeEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
    auto it = _listeners.find(event.name());
    if (it != _listeners.end()) {
      auto &listenersList = it->second;
      for (auto &listener : listenersList) {
        listener.function()(event);
      }
    }
    if (shouldLog) {
      std::cout << fmt::format("GAMEINFO: (emitter) Emitted: \"{}\"\n",
                               event.name());
    }
    if (shouldEmitAfter) {
      auto afterEventName = event.name() + ":after";
      decltype(event) afterEvent{afterEventName, event.value()};
      emit(afterEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};

} // namespace game
