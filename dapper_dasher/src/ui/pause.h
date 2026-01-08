#pragma once
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "async/async-pointer.h"
#include "log/log.h"
#include "raygui.h"
#include "ui/text.h"
#include <string>

namespace game {
class Pause {
  Text textResume{config::PAUSE_TEXT_RESUME};
  bool textResumeIsPressed = false;

  Text textRestart{config::PAUSE_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::PAUSE_TEXT_QUIT};
  bool textQuitIsPressed = false;

  Emitter *emitter = AsyncPointer::get<Emitter>();  
  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();  
  
public:
  Pause();

  void onInit();
  void onUpdate();
  void onRender();
};
} // namespace game
