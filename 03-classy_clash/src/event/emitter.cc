#include "event/emitter.h"

namespace game {

Emitter::~Emitter() {
  for (auto itMap = _listeners.begin(); itMap != _listeners.end();) {
    itMap->second.clear();
    itMap = _listeners.erase(itMap);
  }
}

const Listeners &Emitter::getListeners() const { return _listeners; };

Listener Emitter::on(const std::string &eventName,
                     const ListenerFunction &function) {
  Listener listener{eventName, function};
  _listeners[eventName].push_back(listener);
  return listener;
};

void Emitter::off(const Listener &listener) {
  auto itMap = _listeners.find(listener.getEventName());
  if (itMap != _listeners.end()) {
    itMap->second.remove_if(
        [listener](auto p) { return p.getId() == listener.getId(); });

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
      auto beforeEventName = event.getName() + ":before";
      decltype(event) beforeEvent{beforeEventName, event.getValue()};
      emit(beforeEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
    auto it = _listeners.find(event.getName());
    if (it != _listeners.end()) {
      auto &listenersList = it->second;
      for (auto &listener : listenersList) {
        listener.getFunction()(event);
      }
    }
    if (shouldLog) {
      std::cout << fmt::format("GAMEINFO: (emitter) Emitted: \"{}\"\n",
                               event.getName());
    }
    if (shouldEmitAfter) {
      auto afterEventName = event.getName() + ":after";
      decltype(event) afterEvent{afterEventName, event.getValue()};
      emit(afterEvent,
           {{"log", shouldLog}, {"before", false}, {"after", false}});
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};

} // namespace game
