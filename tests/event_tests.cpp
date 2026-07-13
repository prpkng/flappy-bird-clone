#include <gtest/gtest.h>

#include <ecs/events/event_dispatcher.hpp>

struct TestEvent : public BaseEvent {
    TestEvent(std::string msg) : message(msg) {}
    std::string message{};
};

TEST(EventTests, EventDispatcherBasic) {

    SimpleEventDispatcher dispatcher{};

    TestEvent event { std::string("Hello World") };
    std::string str = "OtherValue";

    dispatcher.subscribe<TestEvent>([&str](const auto event) {
        str = event.message;
    });

    dispatcher.dispatch(event);

    EXPECT_EQ(str, event.message);

}
