#include "ui/text.h"

namespace game {
Text::Text(const std::string &text) : _text(text) {}
Text::Text(const std::string &text, const int &size)
    : _text(text), _size(size) {}

const float Text::getLineHeight() const { return _lineHeightUnit * _size; }
const float Text::getCharWidth() const { return _charWidthUnit * _size; }

void Text::setText(std::string &text) { _text = text; };
const std::string &Text::getText() const { return _text; };

const char *Text::getC_str() const { return _text.c_str(); }

float Text::getWidth() const { return _text.length() * getCharWidth(); }
float Text::getHeight() const { return getLineHeight(); }

const Rectangle &Text::getRectangle() {
  if (_align == GAME_TEXT_ALIGN_LEFT) {
    _rectangle.x = _position.x;
  }
  if (_align == GAME_TEXT_ALIGN_RIGHT) {
    _rectangle.x = _position.x - getWidth();
  }
  if (_align == GAME_TEXT_ALIGN_CENTER) {
    _rectangle.x = _position.x - getWidth() / 2;
  }

  _rectangle.y = _position.y;
  _rectangle.width = getWidth();
  _rectangle.height = getHeight();
  return _rectangle;
}

void Text::setPosition(const Vector2 &position) {
  vector::copy(position, _position);
};
const Vector2 &Text::getPosition() const { return _position; };

void Text::setAlign(GameTextAlign align) { _align = align; };
GameTextAlign Text::getAlign() const { return _align; };

void Text::setSize(int size) { _size = size; };
int Text::getSize() const { return _size; };
} // namespace game
