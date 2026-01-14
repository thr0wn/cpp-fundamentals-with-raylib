#pragma once
#include "raylib.h"
#include <climits>
#include <cmath>
#include <map>

namespace game {
class Tile {
private:
  Rectangle _source;
  Rectangle _destiny;
  Texture2D _texture;
  Color _color = WHITE;

public:
  Tile() = default;

  Tile(const Rectangle &source);

  Rectangle &source();
  const Rectangle &source() const;

  Rectangle &destiny();
  const Rectangle &destiny() const;

  Texture2D &texture();
  const Texture2D &texture() const;

  Color &color();
  const Color &color() const;

  void render() const;
};

class TileAnimation {
private:
  int _counter = 0;
  Vector2 _tile;
  int _tileTotal{INT_MAX};
  int _tileRowSize{INT_MAX};

public:
  TileAnimation(const int &tileTotal);
  TileAnimation(const int &tileTotal, const int &tileRowSize);

  void next();

  Vector2 &tile();
  const Vector2 &tile() const;

  int &tileTotal();
  const int &tileTotal() const;

  int &tileRowSize();
  const int &tileRowSize() const;
};
} // namespace game
