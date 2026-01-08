#pragma once
#include "async/async-pointer.h"
#include "event/emitter.h"
#include "game/game-node.h"
#include "log/log.h"
#include "tile/tile.h"
#include <any>
#include <map>

namespace game {
class TextureLoader {
public:
  bool loaded;

  Emitter *emitter = AsyncPointer::get<Emitter>();
  Log *log = AsyncPointer::get<Log>();

  const char *textureUrls[NUMBER_OF_TEXTURES] = {
      "resources/textures/scarfy.png", "resources/textures/far-buildings.png",
      "resources/textures/back-buildings.png",
      "resources/textures/foreground.png",
      "resources/textures/12_nebula_spritesheet.png"};
  Texture2D textures[NUMBER_OF_TEXTURES];

  TextureLoader() {
    emitter->on("game/init", [this](Event event) { onInit(); });
    emitter->on("game/deinit", [this](Event event) { onDeinit(); });
  };

  void onInit() {
    for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
      textures[i] = LoadTexture(textureUrls[i]);
    }
    loaded = true;
    log->info("(texture-loader) Loaded textures.");
  }

  void onDeinit() {
    for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
      UnloadTexture(textures[i]);
    }
    log->info("(texture-loader) Unloaded textures.");
  }
};
} // namespace game
