#pragma once
#include "config/config.h"
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

  const float lineHeight() const;
  const float charWidth() const;

public:
  Text(const std::string &text);
  Text(const std::string &text, const int &size);

  std::string &string();
  const std::string &string() const;

  const char *c_str() const;

  const float width() const;
  const float height() const;

  const Rectangle rectangle();

  Vector2 &position();
  const Vector2 &position() const;

  GameTextAlign &align();
  const GameTextAlign &align() const;

  int &size();
  const int &size() const;

  void alignCenter();
  void alignLeft();
  void alignRight();
};
} // namespace game
