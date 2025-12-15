#include "event/emitter.h"

namespace game {

void Emitter::on(std::string eventName, Listener listener) {
  std::list<Listener> listenersByEventName;
  try {
    listenersByEventName = listeners.at(eventName);
  } catch (const std::out_of_range &ex) {
    listeners[eventName] = listenersByEventName;
  }
  listenersByEventName.push_back(listener);
};

void Emitter::off(std::string eventName, Listener listener) {
  try {
    std::list<Listener> listenersByEventName = listeners.at(eventName);
    std::list<Listener>::iterator iterator = listenersByEventName.begin();
    for (auto _listener : listenersByEventName) {
      if (_listener.name == listener.name) {
        listenersByEventName.erase(iterator);
        break;
      }
      iterator++;
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};

void Emitter::emit(Event event) {
  try {
    std::list<Listener> listenersByEventName = listeners.at(event.name);
    for (auto listener : listenersByEventName) {
      listener.function(event);
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};
} // namespace game
