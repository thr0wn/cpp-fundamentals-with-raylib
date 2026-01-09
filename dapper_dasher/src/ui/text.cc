#include "ui/text.h"

namespace game {
Text::Text(const std::string &text) : _text(text) {}
Text::Text(const std::string &text, const int &size)
    : _text(text), _size(size) {}

std::string &Text::string() { return _text; };
const std::string &Text::string() const { return _text; };

const char *Text::c_str() const { return _text.c_str(); }

const float Text::width() const { return _text.length() * charWidth(); }
const float Text::height() const { return lineHeight(); }

const Rectangle Text::rectangle() {
  if (_align == GAME_TEXT_ALIGN_LEFT) {
    _rectangle.x = _position.x;
  }
  if (_align == GAME_TEXT_ALIGN_RIGHT) {
    _rectangle.x = _position.x - width();
  }
  if (_align == GAME_TEXT_ALIGN_CENTER) {
    _rectangle.x = _position.x - width() / 2;
  }

  _rectangle.y = _position.y;
  _rectangle.width = width();
  _rectangle.height = height();
  return _rectangle;
}

Vector2 &Text::position() { return _position; };
const Vector2 &Text::position() const { return _position; };

GameTextAlign &Text::align() { return _align; };
const GameTextAlign &Text::align() const { return _align; };

int &Text::size() { return _size; };
const int &Text::size() const { return _size; };

const float Text::lineHeight() const { return _lineHeightUnit * _size; }
const float Text::charWidth() const { return _charWidthUnit * _size; }
} // namespace game
