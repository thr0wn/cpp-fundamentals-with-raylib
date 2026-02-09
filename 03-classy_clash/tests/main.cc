#include <catch2/catch_test_macros.hpp>

#include <map>
#include <string>

#include "game/game.h"
#include "geometry/geometry.h"

TEST_CASE("Emitter should work correctly", "[event][emitter]") {
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
    REQUIRE(emitter.getListeners().size() == 1);
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
    REQUIRE(emitter.getListeners().size() == 1);
    emitter.off(listener);
    REQUIRE(emitter.getListeners().size() == 0);
  };
}

TEST_CASE("Async-pointer should work correctly", "[asyn-pointer]") {
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

TEST_CASE("Node should work correctly", "[node]") {
  SECTION("should add child correctly") {
    game::Node parent;
    game::Node child;

    REQUIRE(parent.getChildren().size() == 0);

    parent.addChild(&child);

    REQUIRE(parent.getChildren().size() == 1);
  }
  SECTION("should remove child correctly") {
    game::Node parent;
    game::Node childA;
    game::Node childB;

    parent.addChild(&childA);
    parent.addChild(&childB);

    REQUIRE(parent.getChildren().size() == 2);

    parent.removeChild(&childB);

    REQUIRE(parent.getChildren().front() == &childA);
    REQUIRE(parent.getChildren().size() == 1);
  }
}

TEST_CASE("NodeManager should work correctly", "[node] [node-manager]") {
  SECTION("should collides correctly") {
    game::NodeManager nodeManager;
    Rectangle rectA{0, 0, 1, 1};    
    game::Geometry childA{&rectA};
    Rectangle rectB{0.5, 0.5, 1, 1};
    game::Geometry childB{&rectB};

    nodeManager.addChild(&childA);
    nodeManager.addChild(&childB);

    REQUIRE(nodeManager.collides(&childA) == &childB);
    REQUIRE(nodeManager.collides(&childB) == &childA);
  }  
}

TEST_CASE("Properties should work correctly", "[node] [node-manager]") {
  SECTION("should set properties correctly") {
    game::Properties props;
    props.set("key1", 0);
    props.set("key2", "string");

    REQUIRE(*props.get<int>("key1") == 0);
    REQUIRE(*props.get<std::string>("key2") == "string");
  }
}
