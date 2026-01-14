#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "log/log.h"
#include "texture/tile.h"
#include <any>
#include <map>

namespace game {
typedef enum GameTexture {
  GAME_TEXTURE_WORLD = 0,
} GameTexture;

class TextureLoader {
private:
  const char *_textureUrls[config::NUMBER_OF_TEXTURES] = {
      "resources/textures/tilemap.png"};
  Texture2D _textures[config::NUMBER_OF_TEXTURES];

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
