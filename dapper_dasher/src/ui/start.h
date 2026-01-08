#pragma once
#include "async/async-pointer.h"
#include "config/config.h"
#include "event/emitter.h"
#include "game/game-state.h"
#include "log/log.h"
#include "raygui.h"
#include "ui/text.h"
#include <string>

namespace game {
class Start {
  Text textNewGame{config::START_TEXT_NEW_GAME};
  bool textNewGameIsPressed = false;

  Text textQuit{config::START_TEXT_QUIT};
  bool textQuitIsPressed = false;

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();

public:
  Start() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  };

  void onInit() {
    textNewGame.setSize(config::TEXT_SIZE_LARGE);
    textNewGame.setPosition(
        {0.025f * config::WINDOW_WIDTH, 0.7f * config::WINDOW_HEIGHT});

    textQuit.setSize(config::TEXT_SIZE_LARGE);
    textQuit.setPosition(
        {0.025f * config::WINDOW_WIDTH,
         textNewGame.getPosition().y + textNewGame.getHeight()});
    log->info("(start-ui) Start UI initialized.");
  }

  void onRender() {
    if (gameState->isStarted()) {
      return;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
    textNewGameIsPressed =
        GuiLabelButton(textNewGame.getRectangle(), textNewGame.getChars());
    textQuitIsPressed =
        GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

    if (!gameState->isStarted() && textNewGameIsPressed) {
      gameState->start();
    }
    if (textQuitIsPressed) {
      gameState->stop();
    }
  }
};
} // namespace game
