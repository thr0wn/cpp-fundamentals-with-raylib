#pragma once
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "async/async-pointer.h"
#include "log/log.h"
#include "raygui.h"
#include "ui/text.h"

namespace game {
class GameOver {
private:  
  Text _textGameOver{config::GAMEOVER_TEXT, config::TEXT_SIZE_LARGE};
  
  Text _textRestart{config::GAMEOVER_TEXT_RESTART, config::TEXT_SIZE_LARGE};
  bool _textRestartIsPressed = false;

  Text _textQuit{config::GAMEOVER_TEXT_QUIT, config::TEXT_SIZE_LARGE};
  bool _textQuitIsPressed = false;

  Emitter *_emitter = AsyncPointer::get<Emitter>();  
  GameState *_gameState = AsyncPointer::get<GameState>();
  Log *_log = AsyncPointer::get<Log>();  

public:
  GameOver();

  void onInit();
  void onRender();
};
} // namespace game
