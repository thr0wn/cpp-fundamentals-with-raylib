#include "game/game.h"

namespace game {
namespace {
std::unique_ptr<Log> log;
std::unique_ptr<GameState> gameState;
std::unique_ptr<Database> database;
std::unique_ptr<TextureLoader> textureLoader;

std::unique_ptr<Background> background;
std::unique_ptr<Player> player;
std::unique_ptr<Nebula> nebula;
std::unique_ptr<UI> ui;

void createInstances() {
  gameEmitter = std::make_unique<Emitter>("game-emitter");

  log = std::make_unique<Log>();
  gameState = std::make_unique<GameState>();
  database = std::make_unique<Database>();
  textureLoader = std::make_unique<TextureLoader>();

  scheduleService = std::make_unique<ScheduleService>();

  background = std::make_unique<Background>();
  player = std::make_unique<Player>();
  nebula = std::make_unique<Nebula>();
  ui = std::make_unique<UI>();
}

void initRaylib() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
}

void update() {
  gameEmitter->emit({"game/update", {}},
                    {{"log", false}, {"before", true}, {"after", true}});
}
void render() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  gameEmitter->emit({"game/render", {}},
                    {{"log", false}, {"before", true}, {"after", true}});
  EndDrawing();
}

void deinitRaylib() { CloseWindow(); }
} // namespace
void init() {
  createInstances();
  initRaylib();
  gameEmitter->emit({"game/init", {}}, {{"before", true}, {"after", true}});
}
void start() {
  while (!(gameState->isStopped() || WindowShouldClose())) {
    update();
    render();
  }
}

void stop() {
  gameEmitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
}

void deinit() {
  gameEmitter->emit({"game/deinit", {}}, {{"before", true}, {"after", true}});
  deinitRaylib();
}
} // namespace game
