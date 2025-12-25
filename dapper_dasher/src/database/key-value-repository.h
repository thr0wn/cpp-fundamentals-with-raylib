#pragma once
#include "config/config.h"
#include "fmt/format.h"
#include "game/game-node.h"
#include "leveldb/db.h"
#include "log/log-service.h"
#include <memory>

namespace game {
class KeyValueRepository : public GameNode {
  leveldb::DB *keyValueDB;
  std::string databaseLocation = config::DATABASE_LOCATION;
  bool started = false;
public:
  KeyValueRepository();

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
  extern std::unique_ptr<KeyValueRepository> keyValueRepository;
} // namespace game
