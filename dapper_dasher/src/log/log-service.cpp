#include "log/log-service.hpp"

namespace game {
void LogService::start() {
  setName("log-service");  
}
void LogService::log(std::string message) {
  printf("GAMELOG: %s\n", message.data());
  fflush(stdout);
}
LogService logService;
} // namespace game
