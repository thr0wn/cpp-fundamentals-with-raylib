#include "game/game.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

namespace game {
namespace {
std::unique_ptr<Emitter> emitter;
std::unique_ptr<Log> log;
std::unique_ptr<GameState> gameState;
std::unique_ptr<Database> database;
std::unique_ptr<TextureLoader> textureLoader;

std::unique_ptr<Background> background;
std::unique_ptr<Player> player;
std::unique_ptr<PlayerScore> playerScore;
std::unique_ptr<Nebula> nebula;
std::unique_ptr<UI> ui;

void createInstances() {
  emitter = std::make_unique<Emitter>();
  AsyncPointer::push(emitter.get());

  log = std::make_unique<Log>();
  AsyncPointer::push(log.get());

  gameState = std::make_unique<GameState>();
  AsyncPointer::push(gameState.get());

  database = std::make_unique<Database>();
  AsyncPointer::push(database.get());

  textureLoader = std::make_unique<TextureLoader>();
  AsyncPointer::push(textureLoader.get());

  background = std::make_unique<Background>();
  AsyncPointer::push(background.get());

  nebula = std::make_unique<Nebula>();
  AsyncPointer::push(nebula.get());

  player = std::make_unique<Player>();
  AsyncPointer::push(player.get());

  playerScore = std::make_unique<PlayerScore>();
  AsyncPointer::push(playerScore.get());

  ui = std::make_unique<UI>();
  AsyncPointer::push(ui.get());
}

} // namespace
void init() {
  createInstances();
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
  gameState->init();
}
void start() {
  while (!(gameState->isStopped() || WindowShouldClose())) {
    gameState->update();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    gameState->render();
    EndDrawing();
  }
  if (WindowShouldClose()) {
    stop();
  }
}

void stop() { gameState->stop(); }

void deinit() {
  gameState->deinit();  
  CloseWindow();
}
} // namespace game
