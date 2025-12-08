#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "ui/start.hpp"
//#include "ui/pause.hpp"
// #include "ui/text.hpp"
// #include "ui/score.hpp"
// #include "ui/game-over.hpp"
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

