#pragma once
#include "config/config.hpp"
#include "fmt/format.h"
#include "game/game-node.hpp"
#include "leveldb/db.h"
#include "log/log-service.hpp"

namespace game {
class DatabaseService : public GameNode {
  leveldb::DB *keyValueDB;
  std::string databaseLocation = config::DATABASE_LOCATION;
  bool started = false;
public:
  DatabaseService();

  // start db connections
  void start();
  // stop db connections
  void stop();

  // key-value database: set
  void set(std::string key, std::string value);
  // key-value database: get
  void get(std::string key, std::string *value);
  // key-value database: unset
  void unset(std::string key);
};
  extern DatabaseService *databaseService;
} // namespace game
