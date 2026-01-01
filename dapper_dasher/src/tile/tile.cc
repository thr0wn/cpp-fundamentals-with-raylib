#include "tile/tile.h"

namespace game {
void Tile::loadTexture(GameTexture gameTexture) {
  gameEmitter->emit({"tile/texture/get", (std::pair<GameTexture, Texture2D *>){
                                             gameTexture, &texture}});
}
void Tile::draw(Vector2 position, Color color) {
  Tile::draw(*this, position, color);
}
void Tile::draw(Tile tile, Vector2 position, Color color) {
  Rectangle source = {(tile.x * tile.width), (tile.y * tile.height), tile.width,
                      tile.height};
  Rectangle destiny = {position.x, position.y, tile.width, tile.height};
  Vector2 origin = {0, 0};
  DrawTexturePro(tile.texture, source, destiny, origin, 0.0f, color);
}
} // namespace game
