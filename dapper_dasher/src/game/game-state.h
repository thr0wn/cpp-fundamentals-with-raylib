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
  void init();
  void update();
  void render();
  void start();
  void restart();
  void pause();  
  void resume();
  void setGameOver();
  void stop();
  void deinit();  

  bool isInitialized();  
  bool isStarted();  
  bool isRunning();  
  bool isPaused();  
  bool isGameOver();
  bool isStopped();
  bool isDeinitialized();  
};
}
