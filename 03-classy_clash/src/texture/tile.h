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

  void setSource(const Rectangle &source);
  Rectangle &getSource();

  void setDestiny(const Rectangle &destiny);
  Rectangle &getDestiny();

  void setTexture(const Texture2D &texture);
  const Texture2D &getTexture() const;

  void setColor(const Color &color);
  const Color &getColor() const;

  void setAnimation(TileAnimation *animation);
  TileAnimation *getAnimation() const;

  void update() override;
  void render() override;
};
} // namespace game
