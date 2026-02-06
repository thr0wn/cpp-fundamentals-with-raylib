#pragma once
#include "geometry/geometry.h"
#include "async/async-pointer.h"
#include "log/log.h"
#include "node/node.h"
#include <map>
#include <list>
#include <string>

namespace game {
  class NodeManager : public Node {
  private:
    std::map<uint, std::list<Node2D*>> nodes;

    Log *_log = AsyncPointer::get<Log>();
  public:
    void addChild(Node *node) override;
    void removeChild(Node *node) override;

    void addGeometry(Node *node);
    void removeGeometry(Node *node);

    Geometry *findCollision(Node *node, Geometry *geometryNode);  
    Geometry *collides(Geometry *geometryNode);

    void update() override;

    void prepareRender();
    Node *traverseSort(Node *node);
    void doRender();
    void render() override;  
  };
} // namespace game
