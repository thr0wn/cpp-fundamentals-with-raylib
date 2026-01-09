#include "game/game.h"

namespace game {
namespace {
std::unique_ptr<Emitter> _emitter;
std::unique_ptr<Log> _log;
std::unique_ptr<GameState> _gameState;
std::unique_ptr<Database> _database;
std::unique_ptr<TextureLoader> _textureLoader;

std::unique_ptr<Background> _background;
std::unique_ptr<Player> _player;
std::unique_ptr<PlayerScore> _playerScore;
std::unique_ptr<Nebula> _nebula;
std::unique_ptr<UI> _ui;

void createInstances() {
  _emitter = std::make_unique<Emitter>();
  AsyncPointer::push(_emitter.get());

  _log = std::make_unique<Log>();
  AsyncPointer::push(_log.get());

  _gameState = std::make_unique<GameState>();
  AsyncPointer::push(_gameState.get());

  _database = std::make_unique<Database>();
  AsyncPointer::push(_database.get());

  _textureLoader = std::make_unique<TextureLoader>();
  AsyncPointer::push(_textureLoader.get());

  _background = std::make_unique<Background>();
  AsyncPointer::push(_background.get());

  _nebula = std::make_unique<Nebula>();
  AsyncPointer::push(_nebula.get());

  _player = std::make_unique<Player>();
  AsyncPointer::push(_player.get());

  _playerScore = std::make_unique<PlayerScore>();
  AsyncPointer::push(_playerScore.get());

  _ui = std::make_unique<UI>();
  AsyncPointer::push(_ui.get());
}

} // namespace
void init() {
  createInstances();
  InitWindow(config::WINDOW_WIDTH, config::WINDOW_HEIGHT,
             config::GAME_NAME.data());
  SetTargetFPS(60);

  // Disable default close with
  SetExitKey(KEY_NULL);
  _gameState->init();
}
void start() {
  while (!(_gameState->stopped() || WindowShouldClose())) {
    _gameState->update();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    _gameState->render();
    EndDrawing();
  }
  if (WindowShouldClose()) {
    stop();
  }
}

void stop() { _gameState->stop(); }

void deinit() {
  _gameState->deinit();  
  CloseWindow();
}
} // namespace game
