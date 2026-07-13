#pragma once

#include <functional>
#include <typeindex>


struct Event {
    virtual ~Event() = default; // Default destructor
};



// Reflection-based simple event dispatcher
class EventDispatcher {
public:
    using Callback = std::function<void(const Event&)>;

    template <typename T>
    void subscribe(std::function<void(const T&)> callback) {
        auto typeIdx = std::type_index(typeid(T));

        auto wrapper = [callback](const Event& event) {
            callback(static_cast<const T&>(event));
        };

        listeners[typeIdx].push_back(wrapper);
    }

    void dispatch(const Event& event) {
        auto typeIdx = std::type_index(typeid(event));
        auto it = listeners.find(typeIdx);

        if (it != listeners.end()) {
            for (const auto& callback : it->second) {
                callback(event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<Callback>> listeners;
};
