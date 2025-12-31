#include "log/log.h"

namespace game {
Log::Log() {
  gameEmitter->on("log/info", [this](Event event) {    
    info(std::any_cast<std::string>(event.value));
  });
}

void Log::info(std::string message) {
  if (enabled)
    std::cout << fmt::format("GAMEINFO: {}\n", message.data());
}

void Log::setEnabled(bool enabled) { this->enabled = enabled; }
bool Log::isEnabled() { return enabled; }

std::unique_ptr<Log> logService;
} // namespace game
