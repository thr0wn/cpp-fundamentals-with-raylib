#include "game/game-node.h"

#include "log/log-service.h"

namespace game {

GameNode::GameNode(std::string name) { this->name = name; }

GameNode2D::GameNode2D(std::string name) : GameNode(name) {}

void GameNode::push(GameNode *gameNode) { children.push_back(gameNode); }

void GameNode::erase(GameNode *gameNode) {
  std::list<GameNode *>::iterator iterator = children.begin();
  for (GameNode *gNode : children) {
    if (gNode->getName() == gameNode->getName()) {
      gNode->_stop();
      children.erase(iterator);
     break;
    }
    iterator++;
  }
}

void GameNode::_start() {
  try {
    logService->info(fmt::format("({}) Starting", getName()));
    start();
    for (GameNode *gameNode : children) {
      gameNode->_start();
    }
    logService->info(fmt::format("({}) Started", getName()));
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at start", getName()));
  }
}

void GameNode::_restart() {
  try {
    logService->info(fmt::format("({}) Restarting", getName()));
    restart();
    for (GameNode *gameNode : children) {
      gameNode->_restart();
    }
    logService->info(fmt::format("({}) Restarted", getName()));
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at restart", getName()));
  }
}

void GameNode::_update() {
  try {
    update();
    for (GameNode *gameNode : children) {
      gameNode->_update();
    }
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at update", getName()));
  }
}

void GameNode::_render() {
  try {
    render();
    for (GameNode *gameNode : children) {
      gameNode->_render();
    }
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at render", getName()));
  }
}

void GameNode::_renderOut() {
  try {
    renderOut();
    for (GameNode *gameNode : children) {
      gameNode->_renderOut();
    }
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at renderOut", getName()));
  }
}

void GameNode::_stop() {
  try {
    logService->info(fmt::format("({}) Stopping", getName()));    
    stop();
    for (GameNode *gameNode : children) {
      gameNode->_stop();
    }
    children.clear();
    logService->info(fmt::format("({}) Stopped", getName()));
  } catch (...) {
    logService->info(fmt::format("({}) Crashed at stop", getName()));
  }
}

void GameNode::setName(std::string name) { this->name = name; }

std::string GameNode::getName() { return name; }

} // namespace game
