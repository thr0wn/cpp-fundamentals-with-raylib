#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "ui/start.h"
#include "ui/pause.h"
#include "ui/text.h"
#include "ui/score.h"
#include "ui/game-over.h"
#include <string>

namespace game {
class UI {
  Start startUI;
  Pause pauseUI;
  Score scoreUI;
  GameOver gameOverUI;
};
} // namespace game

