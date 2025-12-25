#include "game/game.h"

namespace game {
int start() {
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
  // gameService->push(&logService);
  // gameService->push(&scheduleService);
  // gameService->push(&tileService);
  // gameService->push(&background);
  // gameService->push(&databaseService); // must be after others
  // gameService->push(&player);
  // gameService->push(&nebula);
  // gameService->push(&ui);

  gameService->start();
  while (!gameService->shouldClose()) {
    gameService->update();
    gameService->render();
  }
  gameService->stop();

  return 0;
}

void stop() { gameService->stopGame(); }

} // namespace game
