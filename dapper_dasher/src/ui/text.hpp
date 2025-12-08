#pragma once
#include "config/config.hpp"
#include "raylib.h"

namespace game {
class Text {
  constexpr static const float lineHeightUnit = config::TEXT_LINE_HEIGHT_UNIT;
  constexpr static const float lineWidthUnit = config::TEXT_LINE_WIDTH_UNIT;
  std::string text;
  float size;
  Rectangle rectangle;
  Vector2 position;
  void updateRectangle();

public:
  Text(std::string text);

  std::string getString();
  char *getChars();

  float getWidth();
  float getHeight();

  Rectangle getRectangle();

  void setPosition(Vector2 position);
  Vector2 getPosition();

  void setSize(float size);
  float getSize();

  float getLineHeight();
  float getLineWidth();

  void alignCenter();
  void alignLeft();
  void alignRight();
};
} // namespace game
