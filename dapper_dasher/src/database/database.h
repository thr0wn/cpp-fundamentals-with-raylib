#pragma once
#include "config/config.h"
#include "event/emitter.h"
#include "fmt/format.h"
#include "async/async-pointer.h"
#include "leveldb/db.h"
#include "log/log.h"
#include <memory>
#include <any>
#include <map>

namespace game {
class Database {
  leveldb::DB *_keyValueDB;
  std::string _databaseLocation = config::DATABASE_LOCATION;
  bool _started = false;
  Log *_log = AsyncPointer::get<Log>();
  Emitter *_emitter = AsyncPointer::get<Emitter>();

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
