#pragma once

#include "ecs/schedules.hpp"
#include "ecs/plugin.hpp"

#include <entt/entt.hpp>

class SystemEventDispatcher;
class SystemScheduler;

template <typename T>
concept IsPlugin = std::is_base_of<Plugin, T>::value;

class World {
public:
	World();
	~World();

	std::vector<Plugin*> plugins;

	SystemScheduler* scheduler;
	SystemEventDispatcher* system_dispatcher;
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
	auto* plugin = plugins.emplace_back(new T());
	plugin->setup(*this);

	return *this;
}
