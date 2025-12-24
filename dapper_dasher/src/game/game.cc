#include "game/game.h"

namespace game {
int start() {
  UI ui;
  Background background;
  Player player;
  Nebula nebula;
  gameService.push(&logService);
  gameService.push(&scheduleService);
  gameService.push(&tileService);
  gameService.push(&background);
  gameService.push(&databaseService); // must be after others
  gameService.push(&player);
  gameService.push(&nebula);
  gameService.push(&ui);

  gameEmitter.start();
  while (!gameService.shouldClose()) {
    gameEmitter.update();
    gameEmitter.render();
  }
  gameEmitter.stop();
  
  return 0;
}

void stop() { gameService.stopGame(); }

} // namespace game
