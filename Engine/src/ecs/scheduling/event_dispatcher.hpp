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
    void subscribe(std::function<void(const T&)> callback);

    void dispatch(const Event& event);

private:
    std::unordered_map<std::type_index, std::vector<Callback>> listeners;
};

template <typename T>
inline void EventDispatcher::subscribe(std::function<void(const T&)> callback) {
    auto typeIdx = std::type_index(typeid(T));

    auto wrapper = [callback](const Event& event) {
        callback(static_cast<const T&>(event));
    };

    listeners[typeIdx].push_back(wrapper);
}

class SystemEventDispatcher {
public:
    SystemEventDispatcher(World* worldPtr) : world(worldPtr) {}

    using Callback = std::function<void(const Event&, World& world)>;

    template <typename Ev, typename Func>
    void subscribe(Func&& func);

    template <typename Ev, typename T, typename Func>
    void subscribe(T* instance, Func&& func);

    void dispatch(const Event& event);

private:
    World* world;
    std::unordered_map<std::type_index, std::vector<Callback>> listeners{};
};

template <typename Ev, typename Func>
inline void SystemEventDispatcher::subscribe(Func&& func) {
    using traits = callable_traits<std::decay_t<Func>>;
    using args = traits::args;
    using event_t = std::decay_t<typename pop_front<args>::front>;
    using deps_t = typename pop_front<args>::type;
    static_assert(std::is_same_v<std::decay_t<Ev>, std::decay_t<event_t>>);

    auto bind_event = [&, func = std::forward<Func>(func)](const Ev& ev) {
        return [&](auto&&... args) {
            return std::invoke(func, ev, std::forward<decltype(args)>(args)...);
        };
    };

    Callback wrapper;

    if constexpr (std::is_same_v<std::remove_cvref_t<first_type_t<deps_t>>,
                                 World>) {
        wrapper = [func = std::forward<Func>(func)](const Event& event,
                                                    World& world) {
            std::invoke(func, static_cast<const Ev&>(event), world);
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


template <typename Ev, typename T, typename Func>
inline void SystemEventDispatcher::subscribe(T* instance, Func&& func) {
    using traits = callable_traits<std::decay_t<Func>>;
    using args = traits::args;
    using event_t = std::decay_t<typename pop_front<args>::front>;
    using deps_t = typename pop_front<args>::type;
    static_assert(std::is_same_v<std::decay_t<Ev>, std::decay_t<event_t>>);

    auto bind_event = [&, instance, func = std::forward<Func>(func)](event_t& ev) {
        return [&](auto&&... args) {
            return std::invoke(func, instance, ev, std::forward<decltype(args)>(args)...);
        };
    };

    Callback wrapper;

    if constexpr (std::is_same_v<std::remove_cvref_t<first_type_t<deps_t>>,
                                 World>) {
        wrapper = [instance, func = std::forward<Func>(func)](const Event& event,
                                                    World& world) {
            std::invoke(func, instance, static_cast<const Ev&>(event), world);
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
