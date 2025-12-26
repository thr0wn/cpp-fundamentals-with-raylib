#include "game/game.h"

namespace game {
void init() {
  logService = std::make_unique<LogService>();
  gameEmitter = std::make_unique<Emitter>("game-emitter");
  gameService = std::make_unique<GameService>();
  tileService = std::make_unique<TileService>();
  scheduleService = std::make_unique<ScheduleService>();
  keyValueRepository = std::make_unique<KeyValueRepository>();

  UI ui;
  background = std::make_unique<Background>();
  Player player;
  Nebula nebula;

  gameService->init();
}
void update() {
  gameService->update();
  gameService->render();
}
void start() {
  while (!gameService->shouldClose()) {
    update();
  }
}

void stop() { gameService->stop(); }

void deinit() { gameService->deinit(); }
} // namespace game
