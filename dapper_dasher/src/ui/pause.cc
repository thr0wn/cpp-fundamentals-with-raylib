#include "ui/pause.h"

namespace game {
Pause::Pause() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/update", [this](Event event) { onUpdate(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
};

void Pause::onInit() {
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
  textQuit.setPosition({0.5 * config::WINDOW_WIDTH,
                        textRestart.getPosition().y + textRestart.getHeight()});
  textQuit.alignCenter();
  log->info("(pause-ui) Pause UI initialized.");
}

void Pause::onUpdate() {
  if (gameState->isRunning() &&
      (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER))) {
    gameEmitter->emit({"game/pause", {}}, {{"before", true}, {"after", true}});
  }
}

void Pause::onRender() {
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
    gameEmitter->emit({"game/resume", {}}, {{"before", true}, {"after", true}});
  }
  if (textRestartIsPressed) {
    gameEmitter->emit({"game/restart", {}}, {{"before", true}, {"after", true}});
  }
  if (textQuitIsPressed) {
    gameEmitter->emit({"game/stop", {}}, {{"before", true}, {"after", true}});
  }
}
} // namespace game
