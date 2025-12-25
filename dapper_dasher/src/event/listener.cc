#include "event/listener.h"

namespace game {
uint Listener::idCounter = 0;
Listener::Listener(std::string eventName, ListenerFunction function)
    : eventName(eventName), function(function) {
  id = idCounter++;
}
} // namespace game
