#include "ecs/events/event_dispatcher.hpp"

void SystemEventDispatcher::dispatch(const BaseEvent& event) {
    auto typeIdx = std::type_index(typeid(event));
    auto it = listeners.find(typeIdx);

    if (it != listeners.end()) {
        for (const auto& callback : it->second) {
            callback(event, *world);
        }
    }
}

void SimpleEventDispatcher::dispatch(const BaseEvent& event) {
    auto typeIdx = std::type_index(typeid(event));
    auto it = listeners.find(typeIdx);

    if (it != listeners.end()) {
        for (const auto& callback : it->second) {
            callback(event);
        }
    }
}
