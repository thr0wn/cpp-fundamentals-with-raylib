#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "log/log.h"
#include "config/config.h"
#include "game/game-state.h"
#include "player/player-score.h"
#include "raygui.h"
#include "ui/text.h"
#include <fmt/format.h>
#include <string>

namespace game {
class Score {
private:  
  Text _textScore{config::SCORE_TEXT_SCORE, config::TEXT_SIZE_MEDIUM};

  Text _textHighScore{config::SCORE_TEXT_HIGH_SCORE, config::TEXT_SIZE_MEDIUM};

  Text _textPressSpace{config::SCORE_TEXT_PRESS_SPACE, config::TEXT_SIZE_SMALL};

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  GameState *_gameState = AsyncPointer::get<GameState>();
  PlayerScore *_playerScore = AsyncPointer::get<PlayerScore>();
  Log *_log = AsyncPointer::get<Log>();

public:
  Score();

  void onStart();
  void onRender();
};
} // namespace game
