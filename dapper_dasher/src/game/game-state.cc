#include "game/game-state.h"

namespace game {
void GameState::init() {
  _initialized = true;
  _emitter->emit({"game/init", {}}, {{"before", true}, {"after", true}});
};
void GameState::update() {
  _emitter->emit({"game/update", {}},
                {{"log", false}, {"before", true}, {"after", true}});
};
void GameState::render() {
  _emitter->emit({"game/render", {}},
                {{"log", false}, {"before", true}, {"after", true}});
};
void GameState::start() {
  _started = true;
  _emitter->emit({"game/start", {}}, {{"before", true}, {"after", true}});
};
void GameState::restart() {
  _started = false;
  _paused = false;
  _gameOver = false;  
  _emitter->emit({"game/restart", {}}, {{"before", true}, {"after", true}});
};
void GameState::pause() {
  _paused = true;
  _emitter->emit({"game/pause", {}}, {{"before", true}, {"after", true}});
};
void GameState::resume() {
  _paused = false;
  _emitter->emit({"game/resume", {}}, {{"before", true}, {"after", true}});
};
void GameState::setGameOver() {
  _gameOver = true;
  _emitter->emit({"game/game-over", {}}, {{"before", true}, {"after", true}});
};
void GameState::stop() {
  _stopped = true;
  _emitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
};
void GameState::deinit() {
  _deinitialized = true;
  _emitter->emit({"game/deinit", {}}, {{"before", true}, {"after", true}});
};

bool GameState::initialized() { return _initialized; };
bool GameState::started() { return _started; };
bool GameState::running() { return _started && !_paused && !_gameOver; };
bool GameState::paused() { return _paused; };
bool GameState::gameOver() { return _gameOver; };
bool GameState::stopped() { return _stopped; };
bool GameState::deinitialized() { return _deinitialized; };

} // namespace game
