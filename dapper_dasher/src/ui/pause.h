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
class Pause {
  Text textResume{config::PAUSE_TEXT_RESUME};
  bool textResumeIsPressed = false;

  Text textRestart{config::PAUSE_TEXT_RESTART};
  bool textRestartIsPressed = false;

  Text textQuit{config::PAUSE_TEXT_QUIT};
  bool textQuitIsPressed = false;

  Emitter *emitter = AsyncPointer::get<Emitter>();
  GameState *gameState = AsyncPointer::get<GameState>();
  Log *log = AsyncPointer::get<Log>();

public:
  Pause() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/update", [this](Event event) { onUpdate(); });
    emitter->on("game/render", [this](Event event) { onRender(); });
  };

  void onInit() {
    textResume.setSize(config::TEXT_SIZE_LARGE);
    textResume.setPosition(
        {0.5f * config::WINDOW_WIDTH, 0.35 * config::WINDOW_HEIGHT});
    textResume.alignCenter();

    textRestart.setSize(config::TEXT_SIZE_LARGE);
    textRestart.setPosition(
        {0.5f * config::WINDOW_WIDTH,
         textResume.getPosition().y + textResume.getHeight()});
    textRestart.alignCenter();

    textQuit.setSize(config::TEXT_SIZE_LARGE);
    textQuit.setPosition(
        {0.5 * config::WINDOW_WIDTH,
         textRestart.getPosition().y + textRestart.getHeight()});
    textQuit.alignCenter();
    log->info("(pause-ui) Pause UI initialized.");
  }

  void onUpdate() {
    if (gameState->isRunning() &&
        (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
      gameState->pause();
    }
  }

  void onRender() {
    if (!gameState->isPaused()) {
      return;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_LARGE);
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
    textResumeIsPressed =
        GuiLabelButton(textResume.getRectangle(), textResume.getChars());
    textRestartIsPressed =
        GuiLabelButton(textRestart.getRectangle(), textRestart.getChars());
    textQuitIsPressed =
        GuiLabelButton(textQuit.getRectangle(), textQuit.getChars());

    if (textResumeIsPressed) {
      gameState->resume();
    }
    if (textRestartIsPressed) {
      gameState->restart();
    }
    if (textQuitIsPressed) {
      gameState->stop();
    }
  }
};
} // namespace game
