#include "event/emitter.h"

namespace game {

Emitter::~Emitter() {
  for (auto it = listeners.begin(); it != listeners.end();) {
    auto listenersItem = *it;
    listenersItem.second->clear();
    delete listenersItem.second;
    it = listeners.erase(it);
  }
}

void Emitter::on(std::string eventName, Listener *listener) {
  std::list<Listener *> *listenersByEventName;
  try {
    listenersByEventName = listeners.at(eventName);
  } catch (const std::out_of_range &ex) {
    listenersByEventName = new std::list<Listener *>;
    listeners.insert({eventName, listenersByEventName});
  }
  listenersByEventName->push_back(listener);
};

void Emitter::off(std::string eventName, Listener *listener) {
  auto it = listeners.find(eventName);
  if (it != listeners.end()) {
    it->second->remove_if(
        [listener](auto p) { return p->name == listener->name; });

    if (it->second->empty()) {
      listeners.erase(it);
    }
  }
};

void Emitter::emit(Event event) {
  try {
    for (auto listener : *listeners.at(event.name)) {
      listener->function(event);
    }
  } catch (const std::out_of_range &ex) {
    // do nothing
  }
};
} // namespace game
