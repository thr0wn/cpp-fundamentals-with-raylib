#include <catch2/catch_test_macros.hpp>

#include <cstdio>
#include <map>
#include <string>

#include "game/game.h"

TEST_CASE("Emitter should work properly", "[event][emitter]") {
  game::Emitter emitter;
  std::string eventName0 = "event-0";
  std::string eventName1 = "event-1";
  std::string listenerName0 = "listener-0";
  std::string listenerName1 = "listener-1";
  std::map<std::string, int> calls = {{listenerName0, 0}, {listenerName1, 0}};
  auto listener0 = std::make_unique<game::Listener>(
      listenerName0,
      [&calls, &listenerName0](game::Event event) { calls[listenerName0]++; });
      auto listener1 = std::make_unique<game::Listener>(
      listenerName1,
      [&calls, &listenerName1](game::Event event) { calls[listenerName1]++; });

  SECTION("when adding a listener") {
    emitter.on(eventName0, listener0.get());
    REQUIRE(emitter.listeners.size() == 1);
  };

  SECTION("when emitting events") {
    emitter.on(eventName0, listener0.get());
    emitter.on(eventName1, listener1.get());
    game::Event event0{eventName0, {}};
    emitter.emit(event0);
    game::Event event1{eventName1, {}};
    emitter.emit(event1);
    REQUIRE(calls[listenerName0] == 1);
    REQUIRE(calls[listenerName1] == 1);
  };

  SECTION("when removing a listener") {
    emitter.on(eventName0, listener0.get());
    REQUIRE(emitter.listeners.size() == 1);
    emitter.off(eventName0, listener0.get());
    REQUIRE(emitter.listeners.size() == 0);
  };
}
