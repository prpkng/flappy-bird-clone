#include "ecs/scheduling/event_dispatcher.hpp"

void SystemEventDispatcher::dispatch(const Event& event) {
    auto typeIdx = std::type_index(typeid(event));
    auto it = listeners.find(typeIdx);

    if (it != listeners.end()) {
        for (const auto& callback : it->second) {
            callback(event, *world);
        }
    }
}

void EventDispatcher::dispatch(const Event& event) {
    auto typeIdx = std::type_index(typeid(event));
    auto it = listeners.find(typeIdx);

    if (it != listeners.end()) {
        for (const auto& callback : it->second) {
            callback(event);
        }
    }
}
