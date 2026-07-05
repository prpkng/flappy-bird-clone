#pragma once

#include "ecs/schedules.hpp"
#include "ecs/plugin.hpp"

#include <entt/entt.hpp>

class SystemScheduler;

template <typename T>
concept IsPlugin = std::is_base_of<Plugin, T>::value;

class World {
public:
	World();
	~World();

	SystemScheduler* scheduler;
	entt::registry registry;
	entt::dispatcher dispatcher;

	template <typename T>
	requires (IsPlugin<T>)
	World& with_plugin();

	void initialize();
	void update(float delta);
	void render(float delta);
	void cleanup();
};

template<typename T>
requires (IsPlugin<T>)
inline World& World::with_plugin()
{
	T plugin{};
	plugin.setup(*this);

	return *this;
}
