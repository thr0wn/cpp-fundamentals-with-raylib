#include "ui/score.h"

namespace game {
using config::TEXT_SIZE_SMALL;

Score::Score() {
  gameEmitter->on("game/start", [this](Event event) { onStart(); });
  gameEmitter->on("game/render", [this](Event event) { onRender(); });
};

void Score::onStart() {
  // ui
  textScore.setSize(config::TEXT_SIZE_MEDIUM);
  textScore.setPosition(
      {0.025f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT});

  textHighScore.setSize(config::TEXT_SIZE_MEDIUM);
  textHighScore.setPosition(
      {0.025f * config::WINDOW_WIDTH,
       textScore.getPosition().y + textScore.getHeight()});

  textPressSpace.setSize(config::TEXT_SIZE_SMALL);
  textPressSpace.setPosition(
      {0.975f * config::WINDOW_WIDTH, 0.025f * config::WINDOW_HEIGHT});
  textPressSpace.alignRight();
  log->info("(score-ui) Score UI started.");
}

void Score::onRender() {
  if (!gameState->isRunning()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);

  std::string formattedScore =
    fmt::format("{}: {}", textScore.getChars(), playerScore->getScore());
  GuiLabelButton(textScore.getRectangle(), formattedScore.data());

  std::string formattedHighScore =
      fmt::format("{}: {}", textHighScore.getString(), playerScore->getHighScore());
  GuiLabelButton(textHighScore.getRectangle(), formattedHighScore.data());

  GuiSetStyle(DEFAULT, TEXT_SIZE, TEXT_SIZE_SMALL);
  GuiLabelButton(textPressSpace.getRectangle(), textPressSpace.getChars());
}
} // namespace game
