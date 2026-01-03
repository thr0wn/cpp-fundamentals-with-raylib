#include <catch2/catch_test_macros.hpp>

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
  game::ListenerFunction listener0 =
      [&calls, &listenerName0](game::Event event) { calls[listenerName0]++; };
  game::ListenerFunction listener1 =
      [&calls, &listenerName1](game::Event event) { calls[listenerName1]++; };

  SECTION("when adding a listener") {
    emitter.on(eventName0, listener0);
    REQUIRE(emitter.listeners.size() == 1);
  };

  SECTION("when emitting events") {
    emitter.on(eventName0, listener0);
    emitter.on(eventName1, listener1);
    game::Event event0{eventName0, {}};
    emitter.emit(event0);
    game::Event event1{eventName1, {}};
    emitter.emit(event1);
    REQUIRE(calls[listenerName0] == 1);
    REQUIRE(calls[listenerName1] == 1);
  };

  SECTION("when removing a listener") {
    game::Listener listener = emitter.on(eventName0, listener0);
    REQUIRE(emitter.listeners.size() == 1);
    emitter.off(listener);
    REQUIRE(emitter.listeners.size() == 0);
  };
}

TEST_CASE("Async-pointer should work properly", "[asyn-pointer]") {
  SECTION("with inline definition") {
    std::shared_ptr<int> a0(new int{1});
    std::shared_ptr<float> a1(new float{2.0});
    game::AsyncPointer::push(a0.get());
    game::AsyncPointer::push(a1.get());
    auto b0 = game::AsyncPointer::get<int>();
    auto b1 = game::AsyncPointer::get<float>();

    REQUIRE(*a0 == *b0);
    REQUIRE(*a1 == *b1);
  }
  SECTION("whith scoped definition") {
    game::AsyncPointer::clear();
    std::shared_ptr<int> a0;
    std::shared_ptr<float> a1;
    {
      a0 = std::make_shared<int>(1);
      a1 = std::make_shared<float>(2.0);
      game::AsyncPointer::push(a0.get());
      game::AsyncPointer::push(a1.get());
    }
    auto b0 = game::AsyncPointer::get<int>();
    auto b1 = game::AsyncPointer::get<float>();

    REQUIRE(*a0 == *b0);
    REQUIRE(*a1 == *b1);
  }
}
