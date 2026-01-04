#include "game/game-state.h"

namespace game {
void GameState::init() {
  initialized = true;
  emitter->emit({"game/init", {}}, {{"before", true}, {"after", true}});
};
void GameState::update() {
  emitter->emit({"game/update", {}},
                {{"log", false}, {"before", true}, {"after", true}});
};
void GameState::render() {
  emitter->emit({"game/render", {}},
                {{"log", false}, {"before", true}, {"after", true}});
};
void GameState::start() {
  started = true;
  emitter->emit({"game/start", {}}, {{"before", true}, {"after", true}});
};
void GameState::restart() {
  started = false;
  paused = false;
  gameOver = false;  
  emitter->emit({"game/restart", {}}, {{"before", true}, {"after", true}});
};
void GameState::pause() {
  paused = true;
  emitter->emit({"game/pause", {}}, {{"before", true}, {"after", true}});
};
void GameState::resume() {
  paused = false;
  emitter->emit({"game/resume", {}}, {{"before", true}, {"after", true}});
};
void GameState::setGameOver() {
  gameOver = true;
  emitter->emit({"game/game-over", {}}, {{"before", true}, {"after", true}});
};
void GameState::stop() {
  stopped = true;
  emitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
};
void GameState::deinit() {
  deinitialized = true;
  emitter->emit({"game/deinit", {}}, {{"before", true}, {"after", true}});
};

bool GameState::isInitialized() { return initialized; };
bool GameState::isStarted() { return started; };
bool GameState::isRunning() { return started && !paused && !gameOver; };
bool GameState::isPaused() { return paused; };
bool GameState::isGameOver() { return gameOver; };
bool GameState::isStopped() { return stopped; };
bool GameState::isDeinitialized() { return deinitialized; };

} // namespace game
