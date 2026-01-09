#pragma once
#include "config/config.h"
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "log/log.h"
#include "tile/tile.h"
#include <any>
#include <map>

namespace game {
class TextureLoader {
private:
  const char *_textureUrls[config::NUMBER_OF_TEXTURES] = {
      "resources/textures/scarfy.png", "resources/textures/far-buildings.png",
      "resources/textures/back-buildings.png",
      "resources/textures/foreground.png",
      "resources/textures/12_nebula_spritesheet.png"};
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
