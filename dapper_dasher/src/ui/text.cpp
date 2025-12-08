#include "ui/text.hpp"

namespace game {
Text::Text(std::string text) {
  this->text = text;
  updateRectangle();
}

std::string Text::getString() { return text; }
char *Text::getChars() { return text.data(); }

float Text::getWidth() { return text.length() * getLineWidth(); }
float Text::getHeight() { return getLineHeight(); }

void Text::updateRectangle() {
  rectangle.x = position.x;
  rectangle.y = position.y;
  rectangle.width = getWidth();
  rectangle.height = getHeight();
}
Rectangle Text::getRectangle() { return rectangle; }

void Text::setPosition(Vector2 position) {
  this->position = position;
  updateRectangle();
}

Vector2 Text::getPosition() {
  return position;
}

void Text::setSize(float size) {
  this->size = size;
  updateRectangle();
}

float Text::getSize() { return size; }

float Text::getLineHeight() { return lineHeightUnit * size; }
float Text::getLineWidth() { return lineWidthUnit * size; }

void Text::alignCenter() {
  rectangle.x = position.x - getWidth()/2;
}
void Text::alignLeft() {
  rectangle.x = position.x;
}
void Text::alignRight() {
  rectangle.x = position.x - getWidth();
}
}
