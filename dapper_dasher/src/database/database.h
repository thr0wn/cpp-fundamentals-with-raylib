#pragma once
#include "config/config.h"
#include "fmt/format.h"
#include "async/async-pointer.h"
#include "game/game-emitter.h"
#include "leveldb/db.h"
#include "log/log.h"
#include <memory>
#include <any>
#include <map>

namespace game {
class Database {
  leveldb::DB *keyValueDB;
  std::string databaseLocation = config::DATABASE_LOCATION;
  bool started = false;
  Log *log = AsyncPointer::get<Log>();
public:
  Database();
  
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
} // namespace game
