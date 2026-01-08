#pragma once
#include "geometry/geometry.h"
#include "tile/tile.h"
#include <fmt/format.h>
#include <list>
#include <string>
#include <sys/types.h>

namespace game {
class GameNode {
protected:
  inline static uint idCounter = 0;
  uint id;
  std::string name;
  std::list<GameNode> children;

public:
  GameNode(std::string name) : name(name) { id = idCounter++; }

  void setName(std::string name) { this->name = name; }
  std::string getName() const { return name; }
  uint getId() const { return id; }
  
  void push(GameNode gameNode) { children.push_back(gameNode); }
  void erase(GameNode gameNode) {
    children.remove_if(
        [gameNode](auto child) { return child.getId() == gameNode.getId(); });
  }

  virtual void update() {};  
};

class GameNode2D : public GameNode {
private:
  Tile tile;
  Vector2 position{0};
  Vector2 scale{1, 1};
  Color color;

  Geometry collisionGeometry;
  Geometry updatedCollisionGeometry;

public:
  GameNode2D(std::string name) : GameNode(name) {}

  void setTile(const Tile &tile) { this->tile = tile; }
  Tile &getTile() { return tile; }
  void setPosition(const Vector2 &position) { this->position = position; }
  Vector2 &getPosition() { return position; }
  void setScale(const Vector2 &scale) { this->scale = scale; }
  Vector2 &getScale() { return scale; }
  void setColor(const Color &color) { this->color = color; }
  Color &getColor() { return color; }
  void setCollisionGeometry(const Geometry &collisionGeometry) { this->collisionGeometry = collisionGeometry; }
  Geometry &getCollisionGeometry() { return collisionGeometry; }
  Geometry &getUpdatedCollisionGeometry() { return updatedCollisionGeometry; }

  void update() {
    collisionGeometry.translate(position, updatedCollisionGeometry);    
  }

  void render() const {
    Rectangle source = {(tile.x * tile.width), (tile.y * tile.height),
                        tile.width, tile.height};
    Rectangle destiny = {position.x, position.y, tile.width * scale.x,
                         tile.height * scale.y};
    Vector2 origin = {0, 0};
    DrawTexturePro(tile.texture, source, destiny, origin, 0.0f, color);
  }
};
} // namespace game
