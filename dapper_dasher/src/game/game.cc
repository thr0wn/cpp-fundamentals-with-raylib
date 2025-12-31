#include "game/game.h"

namespace game {
namespace {
std::unique_ptr<Log> log;
std::unique_ptr<Database> database;
std::unique_ptr<Background> background;
std::unique_ptr<Player> player;
std::unique_ptr<Nebula> nebula;
std::unique_ptr<UI> ui;
} // namespace
void init() {
  gameEmitter = std::make_unique<Emitter>("game-emitter");

  log = std::make_unique<Log>();
  database = std::make_unique<Database>();

  gameService = std::make_unique<GameService>();
  tileService = std::make_unique<TileService>();
  scheduleService = std::make_unique<ScheduleService>();
  
  background = std::make_unique<Background>();
  player = std::make_unique<Player>();
  nebula = std::make_unique<Nebula>();
  ui = std::make_unique<UI>();

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
