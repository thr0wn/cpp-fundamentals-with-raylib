#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raygui.h"
#include "ui/text.h"

namespace game {
class GameOver {
  Text textGameOver{config::GAMEOVER_TEXT};

  Text textRestart{config::GAMEOVER_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::GAMEOVER_TEXT_QUIT};
  bool textQuitIsPressed = false;

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();

public:
  GameOver() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  };

  void onInit() {
    textGameOver.setSize(config::TEXT_SIZE_LARGE);
    textGameOver.setPosition(
        {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
    textGameOver.alignCenter();

    textRestart.setSize(config::TEXT_SIZE_LARGE);
    textRestart.setPosition(
        {0.5f * config::WINDOW_WIDTH,
         textGameOver.getPosition().y + textGameOver.getHeight()});
    textRestart.alignCenter();

    textQuit.setSize(config::TEXT_SIZE_LARGE);
    textQuit.setPosition(
        {0.5 * config::WINDOW_WIDTH,
         textRestart.getPosition().y + textRestart.getHeight()});
    textQuit.alignCenter();
    log->info("(game-over-ui) Game Over UI initialized.");
  }

  void onRender() {
    if (!gameState->isGameOver()) {
      return;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

    GuiLabel(textGameOver.getRectangle(), textGameOver.getChars());

    textRestartIsPressed =
        GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());

    textQuitIsPressed =
        GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

    if (textRestartIsPressed) {
      gameState->restart();
    }
    if (textQuitIsPressed) {
      gameState->stop();
    }
  }
};
} // namespace game
