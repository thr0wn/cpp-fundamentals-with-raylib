#pragma once
#include "config/config.h"
#include "geometry/vector.h"
#include "raylib.h"

namespace game {
typedef enum GameTextAlign {
  GAME_TEXT_ALIGN_LEFT = 0,
  GAME_TEXT_ALIGN_RIGHT,
  GAME_TEXT_ALIGN_CENTER
} GameTextAlign;

class Text {
private:
  constexpr static const float _lineHeightUnit = config::TEXT_LINE_HEIGHT_UNIT;
  constexpr static const float _charWidthUnit = config::TEXT_CHAR_WIDTH_UNIT;
  std::string _text;
  int _size;
  Rectangle _rectangle;
  Vector2 _position;
  GameTextAlign _align;

  const float getLineHeight() const;
  const float getCharWidth() const;

public:
  Text(const std::string &text);
  Text(const std::string &text, const int &size);

  void setText(std::string &text);
  const std::string &getText() const;

  const char *getC_str() const;

  float getWidth() const;
  float getHeight() const;

  const Rectangle &getRectangle();

  void setPosition(const Vector2 &position);
  const Vector2 &getPosition() const;

  void setAlign(GameTextAlign align);
  GameTextAlign getAlign() const;

  void setSize(int size);
  int getSize() const;
};
} // namespace game
