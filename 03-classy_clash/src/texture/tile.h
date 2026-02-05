#pragma once
#include "node/node-2d.h"
#include "raylib.h"
#include "texture/tile-animation.h"
#include <map>

namespace game {
class Tile : public Node2D {
private:
  Rectangle _source;
  Rectangle _destiny;
  Texture2D _texture;
  Color _color = WHITE;
  TileAnimation *_animation;

public:
  Tile() = default;

  Tile(float width, float height);

  Rectangle &source();
  const Rectangle &source() const;

  Rectangle &destiny();
  const Rectangle &destiny() const;

  Texture2D &texture();
  const Texture2D texture() const;

  Color &color();
  const Color &color() const;

  TileAnimation *&animation();
  const TileAnimation * const animation() const;

  void update() override;
  void render() const override;
};
} // namespace game
