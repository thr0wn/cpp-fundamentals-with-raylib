#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"

namespace game {
class GameState {
private:  
  bool _initialized = false;  
  bool _started = false;  
  bool _paused = false;
  bool _gameOver = false;
  bool _stopped = false;
  bool _deinitialized = false;
  Emitter *_emitter = AsyncPointer::get<Emitter>();

public:
  void init();
  void update();
  void render();
  void render2d();
  void start();
  void restart();
  void pause();  
  void resume();
  void setGameOver();
  void stop();
  void deinit();  

  bool initialized();  
  bool started();  
  bool running();  
  bool paused();  
  bool gameOver();
  bool stopped();
  bool deinitialized();  
};
}
