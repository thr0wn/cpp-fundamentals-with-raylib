#include "ui/score.hpp"
#include "raygui.h"

namespace game {
void Score::start() {
  setName("score-ui");  
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

  // score
  scheduleService.repeat([this] { score++; }, scoreInterval);
  score = 0;
  std::string highscoreAsString = "0";
  databaseService.get(highScoreKey, &highscoreAsString);
  highScore = std::stoi(highscoreAsString);
}

void Score::update() {
  if (!gameService.isRunning()) {
    return;
  }
  if (score > highScore) {
    highScore = score;
  }
}

void Score::render() {
  if (!gameService.isRunning()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_MEDIUM);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  std::string formattedScore =
      fmt::format("{}: {}", textScore.getChars(), score);
  GuiLabelButton(textScore.getRectangle(), formattedScore.data());

  std::string formattedHighScore =
      fmt::format("{}: {}", textHighScore.getString(), highScore);
  GuiLabelButton(textHighScore.getRectangle(), formattedHighScore.data());

  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SIZE_SMALL);
  GuiLabelButton(textPressSpace.getRectangle(), textPressSpace.getChars());
}

void Score::stop() {
  databaseService.set(highScoreKey, std::to_string(highScore));
}
} // namespace game
