#include "game/game.hpp"

namespace game {
int start() {
  Background background;
  // Player *player = new Player();
  // Nebula *nebula = new Nebula();
  // Start *start = new Start();
  // Pause *pause = new Pause();
  // Score *score = new Score();
  // GameOver *gameOver = new GameOver();
  //gameService.addGameNode(logService);
  //gameService.addGameNode(&scheduleService);
  //gameService.addGameNode(tileService);
  gameService.addGameNode(background);
  // gameService.addGameNode(player);
  // gameService.addGameNode(nebula);
  // gameService.addGameNode(start);
  // gameService.addGameNode(pause);
  // gameService.addGameNode(score);
  // gameService.addGameNode(gameOver);

  gameService._start();
  while (!gameService.shouldClose()) {
    gameService._update();
    gameService._render();
    gameService._renderOut();
  }
  gameService._stop();

  return 0;
}

void stop() { gameService._stop(); }

} // namespace game
