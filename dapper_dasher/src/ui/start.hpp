#pragma once
#include "config/config.hpp"
#include "game/game-node.hpp"
#include "game/game-service.hpp"
#include "ui/text.hpp"
#include <string>

namespace game {
class Start : public GameNode {
  Text textNewGame{config::START_TEXT_NEW_GAME};
  bool textNewGameIsPressed = false;

  Text textQuit{config::START_TEXT_QUIT};
  bool textQuitIsPressed = false;

public:
  void start() override;
  void render() override;
};
} // namespace game
