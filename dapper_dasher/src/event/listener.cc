#include "event/listener.h"

namespace game {
  Listener::Listener(std::string name, ListenerFunction function): name(name), function(function) {}  
}
