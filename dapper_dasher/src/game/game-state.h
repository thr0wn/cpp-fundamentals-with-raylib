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
  GameState();

  void onInit();
  void onStart();
  void onRestart();
  void onPause();  
  void onResume();
  void onGameOver();
  void onStop();
  void onDeinit(); 

  bool isInitialized();  
  bool isStarted();  
  bool isRunning();  
  bool isPaused();  
  bool isGameOver();
  bool isStopped();
  bool isDeinitialized();  
};
}
