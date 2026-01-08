#pragma once
#include "config/config.h"
#include "raylib.h"

namespace game {
class Text {
  constexpr static const float lineHeightUnit = config::TEXT_LINE_HEIGHT_UNIT;
  constexpr static const float lineWidthUnit = config::TEXT_LINE_WIDTH_UNIT;
  std::string text;
  float size;
  Rectangle rectangle;
  Vector2 position;

public:
  Text(std::string text) {
    this->text = text;
    updateRectangle();
  }

  std::string getString() { return text; }
  const char *getChars() { return text.c_str(); }

  float getWidth() { return text.length() * getLineWidth(); }
  float getHeight() { return getLineHeight(); }

  void updateRectangle() {
    rectangle.x = position.x;
    rectangle.y = position.y;
    rectangle.width = getWidth();
    rectangle.height = getHeight();
  }
  Rectangle getRectangle() { return rectangle; }

  void setPosition(Vector2 position) {
    this->position = position;
    updateRectangle();
  }

  Vector2 getPosition() { return position; }

  void setSize(float size) {
    this->size = size;
    updateRectangle();
  }

  float getSize() { return size; }

  float getLineHeight() { return lineHeightUnit * size; }
  float getLineWidth() { return lineWidthUnit * size; }

  void alignCenter() { rectangle.x = position.x - getWidth() / 2; }
  void alignLeft() { rectangle.x = position.x; }
  void alignRight() { rectangle.x = position.x - getWidth(); }
};
} // namespace game
