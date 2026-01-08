#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"

namespace game {
class GameState {
private:
  bool initialized = false;
  bool started = false;
  bool paused = false;
  bool gameOver = false;
  bool stopped = false;
  bool deinitialized = false;
  Emitter *emitter = AsyncPointer::get<Emitter>();

public:
  void init() {
    initialized = true;
    emitter->emit({"game/init", {}}, {{"before", true}, {"after", true}});
  };
  void update() {
    emitter->emit({"game/update", {}},
                  {{"log", false}, {"before", true}, {"after", true}});
  };
  void render() {
    emitter->emit({"game/render", {}},
                  {{"log", false}, {"before", true}, {"after", true}});
  };
  void start() {
    started = true;
    emitter->emit({"game/start", {}}, {{"before", true}, {"after", true}});
  };
  void restart() {
    started = false;
    paused = false;
    gameOver = false;
    emitter->emit({"game/restart", {}}, {{"before", true}, {"after", true}});
  };
  void pause() {
    paused = true;
    emitter->emit({"game/pause", {}}, {{"before", true}, {"after", true}});
  };
  void resume() {
    paused = false;
    emitter->emit({"game/resume", {}}, {{"before", true}, {"after", true}});
  };
  void setGameOver() {
    gameOver = true;
    emitter->emit({"game/game-over", {}}, {{"before", true}, {"after", true}});
  };
  void stop() {
    stopped = true;
    emitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
  };
  void deinit() {
    deinitialized = true;
    emitter->emit({"game/deinit", {}}, {{"before", true}, {"after", true}});
  };

  bool isInitialized() { return initialized; };
  bool isStarted() { return started; };
  bool isRunning() { return started && !paused && !gameOver; };
  bool isPaused() { return paused; };
  bool isGameOver() { return gameOver; };
  bool isStopped() { return stopped; };
  bool isDeinitialized() { return deinitialized; };
};
} // namespace game
