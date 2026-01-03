#include "game/game-state.h"

namespace game {
GameState::GameState() {
  emitter->on("game/init", [this](Event event) { onInit(); });
  emitter->on("game/start", [this](Event event) { onStart(); });
  emitter->on("game/restart", [this](Event event) { onRestart(); });
  emitter->on("game/pause", [this](Event event) { onPause(); });
  emitter->on("game/resume", [this](Event event) { onResume(); });
  emitter->on("game/game-over", [this](Event event) { onGameOver(); });
  emitter->on("game/stop", [this](Event event) { onStop(); });
  emitter->on("game/deinit", [this](Event event) { onDeinit(); });
  emitter->on("game/deinit", [this](Event event) { onDeinit(); });
}

void GameState::onInit() {
  initialized = true;
  emitter->emit({"game/state", this});
};
void GameState::onStart() { started = true; };
void GameState::onRestart() {
  started = false;
  paused = false;
  gameOver = false;
};
void GameState::onPause() { paused = true; };
void GameState::onResume() { paused = false; };
void GameState::onGameOver() { gameOver = true; };
void GameState::onStop() { stopped = true; };
void GameState::onDeinit() { deinitialized = true; };

bool GameState::isInitialized() { return initialized; };
bool GameState::isStarted() { return started; };
bool GameState::isRunning() { return started && !paused; };
bool GameState::isPaused() { return paused; };
bool GameState::isGameOver() { return gameOver; };
bool GameState::isStopped() { return stopped; };
bool GameState::isDeinitialized() { return deinitialized; };

} // namespace game
