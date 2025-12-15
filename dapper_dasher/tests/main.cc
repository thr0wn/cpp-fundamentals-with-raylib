#include <catch2/catch_test_macros.hpp>

#include <map>
#include <string>

#include "game/game.h"

TEST_CASE("Emitter should work properly", "[event][emitter]") {
  game::Emitter emitter;
  std::string eventName0 = "event-0";
  std::string listenerName0 = "listener-0";
  std::map<std::string, int> calls = {{listenerName0, 0}};
  game::Listener listener0{"listener-0",
                           [calls, listenerName0](game::Event event) mutable {
                             calls[listenerName0]++;
                           }};

  SECTION("when adding a listener") {
    emitter.on(eventName0, listener0);
    REQUIRE(emitter.listeners.size() == 1);
  };

  SECTION("when emitting a event") {
    game::Event event{eventName0, {}};
    emitter.emit(event);
    REQUIRE(calls[listenerName0] == 1);
  };

  SECTION("when removing a listener") {
    emitter.off(eventName0, listener0);
    REQUIRE(emitter.listeners.size() == 0);
  };  
}
