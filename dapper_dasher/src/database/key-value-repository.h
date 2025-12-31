#pragma once
#include "config/config.h"
#include "fmt/format.h"
#include "game/game-emitter.h"
#include "leveldb/db.h"
#include <memory>

namespace game {
class KeyValueRepository {
  leveldb::DB *keyValueDB;
  std::string databaseLocation = config::DATABASE_LOCATION;
  bool started = false;
public:
  KeyValueRepository();

  // init db connections
  void onBeforeInit();
  // init db connections
  void onAfterDeinit();

  // key-value database: set
  void set(std::string key, std::string value);
  // key-value database: get
  void get(std::string key, std::string *value);
  // key-value database: unset
  void unset(std::string key);
};
  extern std::unique_ptr<KeyValueRepository> keyValueRepository;
} // namespace game
