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
private:  
  Text _textResume{config::PAUSE_TEXT_RESUME, config::TEXT_SIZE_LARGE};
  bool _textResumeIsPressed = false;

  Text _textRestart{config::PAUSE_TEXT_RESTART, config::TEXT_SIZE_LARGE};
  bool _textRestartIsPressed = false;

  Text _textQuit{config::PAUSE_TEXT_QUIT, config::TEXT_SIZE_LARGE};
  bool _textQuitIsPressed = false;

  Emitter *_emitter = AsyncPointer::get<Emitter>();  
  GameState *_gameState = AsyncPointer::get<GameState>();
  Log *_log = AsyncPointer::get<Log>();
  
public:
  Pause();

  void onInit();
  void onUpdate();
  void onRender();
};
} // namespace game
