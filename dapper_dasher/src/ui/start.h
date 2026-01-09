#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "ui/text.h"
#include <string>

namespace game {
class Start {
private:
  Text _textNewGame{config::START_TEXT_NEW_GAME, config::TEXT_SIZE_LARGE};
  bool _textNewGameIsPressed = false;

  Text _textQuit{config::START_TEXT_QUIT, config::TEXT_SIZE_LARGE};
  bool _textQuitIsPressed = false;

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  GameState *_gameState = AsyncPointer::get<GameState>();
  Log *_log = AsyncPointer::get<Log>();

public:
  Start();

  void onInit();
  void onRender();
};
} // namespace game
