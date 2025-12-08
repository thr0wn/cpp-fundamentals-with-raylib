#include "game/game-node.hpp"

#include "log/log-service.hpp"

namespace game {

bool operator== (GameNode g1, GameNode g2)  {
  return &g1 == &g2;
}

void GameNode::addGameNode(GameNode gameNode) { children.push_back(gameNode); }

void GameNode::removeGameNode(GameNode gameNode) {
  std::list<GameNode>::iterator iterator;
  bool found = false;
  for (GameNode gNode : children) {
    if (gNode == gameNode) {
      gameNode.stop();
      found = true;
      break;
    }
    iterator++;
  }
  if (found) {
    children.erase(iterator);
  }
}

void GameNode::_start() {
  try {
    start();
    for (GameNode gameNode : children) {
      gameNode._start();
    }
    logService.log(fmt::format("({}) Started", getName()));
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at start", getName()));
  }
}

void GameNode::_restart() {
  try {
    restart();
    for (GameNode gameNode : children) {
      gameNode._restart();
    }
    logService.log(fmt::format("({}) Restarted", getName()));
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at restart", getName()));
  }
}

void GameNode::_update() {
  try {
    update();
    for (GameNode gameNode : children) {
      gameNode._update();
    }
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at update", getName()));
  }
}

void GameNode::_render() {
  try {
    render();
    for (GameNode gameNode : children) {
      gameNode._render();
    }
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at render", getName()));
  }
}

void GameNode::_renderOut() {
  try {
    renderOut();
    for (GameNode gameNode : children) {
      gameNode._renderOut();
    }
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at renderOut", getName()));
  }
}

void GameNode::_stop() {
  try {
    stop();
    for (GameNode gameNode : children) {
      gameNode._stop();
    }
    children.clear();
    logService.log(fmt::format("({}) Stopped", getName()));
  } catch (...) {
    logService.log(fmt::format("({}) Crashed at stop", getName()));
  }
}

void GameNode::setName(std::string name) { this->name = name; }

std::string GameNode::getName() { return name; }

} // namespace game
