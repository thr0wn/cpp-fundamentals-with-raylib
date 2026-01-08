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
class Emitter {
public:
  inline const static EmitOptions DEFAULT_EMIT_OPTIONS = {
      {"log", true}, {"before", false}, {"after", false}};

  std::map<std::string, std::list<Listener>> listeners;

  ~Emitter() {
    for (auto itMap = listeners.begin(); itMap != listeners.end();) {
      itMap->second.clear();
      itMap = listeners.erase(itMap);
    }
  }

  Listener on(std::string eventName, ListenerFunction function) {
    Listener listener{eventName, function};
    listeners[eventName].push_back(listener);
    return listener;
  };

  void off(Listener listener) {
    auto itMap = listeners.find(listener.eventName);
    if (itMap != listeners.end()) {
      itMap->second.remove_if(
          [listener](auto p) { return p.id == listener.id; });

      if (itMap->second.empty()) {
        listeners.erase(itMap);
      }
    }
  };

  void emit(Event event) { emit(event, DEFAULT_EMIT_OPTIONS); };

  void emit(Event event, EmitOptions options) {
    try {
      EmitOptions finalOptions = DEFAULT_EMIT_OPTIONS;
      for (const auto &option : options) {
        finalOptions[option.first] = option.second;
      }
      bool shouldLog = std::any_cast<bool>(finalOptions["log"]);
      bool shouldEmitBefore = std::any_cast<bool>(finalOptions["before"]);
      bool shouldEmitAfter = std::any_cast<bool>(finalOptions["after"]);
      if (shouldEmitBefore) {
        auto beforeEventName = event.name + ":before";
        decltype(event) beforeEvent{beforeEventName, event.value};
        emit(beforeEvent,
             {{"log", shouldLog}, {"before", false}, {"after", false}});
      }
      auto it = listeners.find(event.name);
      if (it != listeners.end()) {
        auto &listenersList = it->second;
        for (auto &listener : listenersList) {
          listener.function(event);
        }
      }
      if (shouldLog) {
        std::cout << fmt::format("GAMEINFO: (emitter) Emitted: \"{}\"\n",
                                 event.name);
      }
      if (shouldEmitAfter) {
        auto afterEventName = event.name + ":after";
        decltype(event) afterEvent{afterEventName, event.value};
        emit(afterEvent,
             {{"log", shouldLog}, {"before", false}, {"after", false}});
      }
    } catch (const std::out_of_range &ex) {
      // do nothing
    }
  };
};
} // namespace game
