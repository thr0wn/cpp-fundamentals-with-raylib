#include "game/game.h"

namespace game {
namespace {
std::shared_ptr<Emitter> emitter;
std::shared_ptr<Log> log;
std::shared_ptr<GameState> gameState;
std::shared_ptr<Database> database;
std::shared_ptr<TextureLoader> textureLoader;

std::shared_ptr<Background> background;
std::shared_ptr<Player> player;
std::shared_ptr<PlayerScore> playerScore;
std::shared_ptr<Nebula> nebula;
std::shared_ptr<UI> ui;

void createInstances() {
  emitter = std::make_shared<Emitter>();
  AsyncPointer::push(emitter.get());

  log = std::make_shared<Log>();
  AsyncPointer::push(log.get());

  gameState = std::make_shared<GameState>();
  AsyncPointer::push(gameState.get());

  database = std::make_shared<Database>();
  AsyncPointer::push(database.get());

  textureLoader = std::make_shared<TextureLoader>();
  AsyncPointer::push(textureLoader.get());

  background = std::make_shared<Background>();
  AsyncPointer::push(background.get());

  player = std::make_shared<Player>();
  AsyncPointer::push(player.get());

  playerScore = std::make_shared<PlayerScore>();
  AsyncPointer::push(playerScore.get());  

  nebula = std::make_shared<Nebula>();
  AsyncPointer::push(nebula.get());

  ui = std::make_shared<UI>();
  AsyncPointer::push(ui.get());
}

void initRaylib() {
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
}

void update() {
  emitter->emit({"game/update", {}},
                    {{"log", false}, {"before", true}, {"after", true}});
}
void render() {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  emitter->emit({"game/render", {}},
                    {{"log", false}, {"before", true}, {"after", true}});
  EndDrawing();
}

void deinitRaylib() { CloseWindow(); }
} // namespace
void init() {
  createInstances();
  initRaylib();
  emitter->emit({"game/init", {}}, {{"before", true}, {"after", true}});
}
void start() {  
  while (!(gameState->isStopped() || WindowShouldClose())) {
    update();
    render();
  }
  if (WindowShouldClose()) {
    stop();
  }
}

void stop() {
  emitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
}

void deinit() {
  emitter->emit({"game/deinit", {}}, {{"before", true}, {"after", true}});
  deinitRaylib();
}
} // namespace game
