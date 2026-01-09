#pragma once
#include "raylib.h"
#include <map>
#include <climits>
#include <cmath>

namespace game {
typedef enum GameTexture {
  TEXTURE_SCARFY = 0,
  TEXTURE_FAR_BUILDING,
  TEXTURE_BACK_BUILDING,
  TEXTURE_NEAR_BUILDING,
  TEXTURE_NEBULA
} GameTexture;

class Tile : public Rectangle {
private:  
  Texture2D _texture;
public:
  Texture2D &texture();
  const Texture2D &texture() const;
};

class TileAnimation {
private:
  int _counter = 0;  
  Vector2 _sprite;
  int _spriteTotal{INT_MAX};
  int _spriteRowSize{INT_MAX};

public:
  TileAnimation(const int &spriteTotal);  
  TileAnimation(const int &spriteTotal, const int &spriteRowSize);

  void next();

  Vector2 &sprite();
  const Vector2 &sprite() const;

  int &spriteTotal();
  const int &spriteTotal() const;

  int &spriteRowSize();  
  const int &spriteRowSize() const;  
};
} // namespace game
