#pragma once

#include "ecs/scheduling/callable_traits.hpp"
#include "ecs/scheduling/system_runner.hpp"
#include "ecs/world.hpp"
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

class SystemEventDispatcher {
public:
    SystemEventDispatcher(World* worldPtr) : world(worldPtr) {}

    using Callback = std::function<void(const Event&, World& world)>;

    template <typename Ev, typename Func> inline void subscribe(Func&& func) {
        using traits = callable_traits<std::decay_t<Func>>;
        using args = traits::args;
        using event_t = typename pop_front<args>::front;
        static_assert(std::is_same_v<std::decay_t<Ev>, std::decay_t<event_t>>);
        using deps_t = typename pop_front<args>::type;

        auto bind_event = [&, func = std::forward<Func>(func)](event_t& ev) {
            return [&](auto&&... args) {
                return std::invoke(func, ev,
                                   std::forward<decltype(args)>(args)...);
            };
        };

        Callback wrapper;

        if constexpr (std::is_same_v<std::remove_cvref_t<first_type_t<deps_t>>,
                                     World>) {
            wrapper = [func = std::forward<Func>(func)](const Event& event, World& world) {
                func(static_cast<const Ev&>(event), world);
            };
        } else {
            wrapper = [bind_event](const Event& event, World& world) {
                auto bound = bind_event(static_cast<const Ev&>(event));

                system_runner<deps_t>::run(world.registry, bound);
            };
        }
        auto typeIdx = std::type_index(typeid(event_t));
        listeners[typeIdx].push_back(wrapper);
    }

    void dispatch(const Event& event) {
        auto typeIdx = std::type_index(typeid(event));
        auto it = listeners.find(typeIdx);

        if (it != listeners.end()) {
            for (const auto& callback : it->second) {
                callback(event, *world);
            }
        }
    }

private:
    World* world;
    std::unordered_map<std::type_index, std::vector<Callback>> listeners{};
};
