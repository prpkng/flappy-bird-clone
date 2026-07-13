#include <gtest/gtest.h>

#include <ecs/scheduling/event_dispatcher.hpp>

struct TestEvent : public Event {
    TestEvent(std::string msg) : message(msg) {}
    std::string message{};
};

TEST(EventTests, EventDispatcherBasic) {

    EventDispatcher dispatcher{};

    TestEvent event { std::string("Hello World") };
    std::string str = "OtherValue";

    dispatcher.subscribe<TestEvent>([&str](const auto event) {
        str = event.message;
    });

    dispatcher.dispatch(event);

    EXPECT_EQ(str, event.message);

}
