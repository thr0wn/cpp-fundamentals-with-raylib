#include "ui/score.hpp"

void Score::start() {
  // ui  
  textScoreRec.x = 0.025f * config::WINDOW_WIDTH;
  textScoreRec.y = 0.025f * config::WINDOW_HEIGHT;
  textScoreRec.width =
      config::TEXT_UNIT_WITDH * config::TEXT_MEDIUM_SIZE * textScore.length();
  textScoreRec.height = config::TEXT_UNIT_HEIGHT * config::TEXT_MEDIUM_SIZE;

  textHighScoreRec.x = 0.025f * config::WINDOW_WIDTH;
  textHighScoreRec.y = textScoreRec.y + 10. +
                       config::TEXT_UNIT_HEIGHT * config::TEXT_MEDIUM_SIZE;
  textHighScoreRec.width = config::TEXT_UNIT_WITDH * config::TEXT_MEDIUM_SIZE *
                           textHighScore.length();
  textHighScoreRec.height = config::TEXT_UNIT_HEIGHT;

  textPressSpaceRec.x = 0.975f * config::WINDOW_WIDTH;
  textPressSpaceRec.y = 0.025f * config::WINDOW_HEIGHT;
  textPressSpaceRec.width = config::TEXT_UNIT_WITDH * config::TEXT_SMALL_SIZE *
                            textPressSpace.length();
  textPressSpaceRec.height = config::TEXT_UNIT_HEIGHT * config::TEXT_SMALL_SIZE;
  textPressSpaceRec.x -= textPressSpaceRec.width;

  // score  
  scheduleService::repeat([this] { score++; }, scoreInterval);  
  score = 0;  
  std::string highscoreAsString = "0";
  databaseService::get(highScoreKey, &highscoreAsString);
  highScore = std::stoi(highscoreAsString);
}

void Score::update() {
  if (!gameService::isRunning()) {
    return;
  }
  if (score > highScore) {
    highScore = score;
  }
}

void Score::render() {
  if (!gameService::isRunning()) {
    return;
  }
  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_MEDIUM_SIZE);
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, config::TEXT_COLOR);
  std::string formattedScore = fmt::format("{}: {}", textScore.data(), score);
  GuiLabelButton(textScoreRec, formattedScore.data());

  std::string formattedHighScore =
  fmt::format("{}: {}", textHighScore.data(), highScore);
  GuiLabelButton(textHighScoreRec, formattedHighScore.data());

  GuiSetStyle(DEFAULT, TEXT_SIZE, config::TEXT_SMALL_SIZE);
  GuiLabelButton(textPressSpaceRec, textPressSpace.data());
}

void Score::stop() {
  databaseService::set(highScoreKey, std::to_string(highScore));
}  
