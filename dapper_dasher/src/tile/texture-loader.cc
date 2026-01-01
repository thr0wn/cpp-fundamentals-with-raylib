#include "tile/texture-loader.h"

namespace game {
TextureLoader::TextureLoader() {
  gameEmitter->on("game/init", [this](Event event) { onInit(); });
  gameEmitter->on("game/deinit", [this](Event event) { onDeinit(); });

  gameEmitter->on("tile/texture/get", [this](Event event) {
    if(!loaded) {
      return;
    }
    auto texs = std::any_cast<std::pair<GameTexture, Texture2D *>>(event.value);
    *texs.second = textures[texs.first];
  });
};

void TextureLoader::onInit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    textures[i] = LoadTexture(textureUrls[i]);
  }
  loaded = true;  
  gameEmitter->emit(
      {"log/info", std::string("(texture-loader) Loaded textures.")});
}

void TextureLoader::onDeinit() {
  for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
    UnloadTexture(textures[i]);
  }
  gameEmitter->emit(
      {"log/info", std::string("(texture-loader) Unloaded textures.")});
}

} // namespace game
