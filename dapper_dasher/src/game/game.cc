#include "game/game.h"

namespace game {
void init() {
  logService = std::make_unique<LogService>();
  scheduleService = std::make_unique<ScheduleService>();
  tileService = std::make_unique<TileService>();
  keyValueRepository = std::make_unique<KeyValueRepository>();
  gameEmitter = std::make_unique<Emitter>("game-emitter");
  gameService = std::make_unique<GameService>();

  UI ui;
  Background background;
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
