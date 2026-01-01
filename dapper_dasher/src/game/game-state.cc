#include "game/game-state.h"

namespace game {
GameState::GameState() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/restart", [this](Event event) { onRestart(); });
  gameEmitter->on("game/pause", [this](Event event) { onPause(); });
  gameEmitter->on("game/resume", [this](Event event) { onResume(); });
  gameEmitter->on("game/game-over", [this](Event event) { onGameOver(); });
  gameEmitter->on("game/stop", [this](Event event) { onStop(); });
  gameEmitter->on("game/deinit", [this](Event event) { onDeinit(); });
  gameEmitter->on("game/deinit", [this](Event event) { onDeinit(); });
}

void GameState::onInit() {
  initialized = true;
  gameEmitter->emit({"game/state", this});
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
