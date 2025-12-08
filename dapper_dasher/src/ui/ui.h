#pragma once
#include "config/config.h"
#include "game/game-node.h"
#include "game/game-service.h"
#include "ui/start.h"
//#include "ui/pause.h"
// #include "ui/text.h"
// #include "ui/score.h"
// #include "ui/game-over.h"
#include <string>

namespace game {
class UI : public GameNode {
  Start *startUI;
  // Pause *pauseUI;
  // Score *scoreUI;
  // GameOver *gameOverUI;

public:
  UI();
  
  void start() override;
  void stop() override;
};
} // namespace game

