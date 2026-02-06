#include "event/listener.h"

namespace game {
Listener::Listener(const std::string &eventName,
                   const ListenerFunction &function)
    : _eventName(eventName), _function(function) {
  _id = _idCounter++;
}

const std::uint32_t &Listener::getId() const { return _id; };

const std::string &Listener::getEventName() const { return _eventName; }

const ListenerFunction &Listener::getFunction() const { return _function; }

} // namespace game
