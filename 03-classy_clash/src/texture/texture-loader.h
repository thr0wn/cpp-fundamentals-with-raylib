#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "log/log.h"
#include "texture/tile.h"
#include <any>
#include <cstring>
#include <map>

namespace game {
typedef enum GameTexture {
  GAME_TEXTURE_WORLD_FOREST = 0,
  GAME_TEXTURE_CHARACTER_KNIGHT_IDLE,
} GameTexture;

class TextureLoader {
private:
  char *_textureUrls[config::TEXTURES_SIZE];
  Texture2D _textures[config::TEXTURES_SIZE];

  Emitter *_emitter = AsyncPointer::get<Emitter>();
  Log *_log = AsyncPointer::get<Log>();

public:
  TextureLoader();

  void onInit();
  void onDeinit();

  const char * const*textureUrls() const;
  const Texture2D *textures() const;
};
} // namespace game
