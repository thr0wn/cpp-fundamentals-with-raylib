#include "log/log-service.h"

namespace game {
LogService::LogService() : GameNode("log-service") {}

void LogService::log(std::string message) {
  if(enabled)  
    std::cout << fmt::format("GAMELOG: {}\n", message.data());
}

void LogService::setEnabled(bool enabled) {
  this->enabled = enabled;
}

LogService logService;
} // namespace game
