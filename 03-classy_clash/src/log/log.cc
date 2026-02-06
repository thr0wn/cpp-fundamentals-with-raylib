#include "log/log.h"

namespace game {
void Log::info(const std::string &message) {
  if (_enabled)
    std::cout << fmt::format("GAMEINFO: {}\n", message);
}

void Log::setEnabled(bool enabled) { _enabled = enabled; }
bool Log::getEnabled() const { return _enabled; }
} // namespace game
