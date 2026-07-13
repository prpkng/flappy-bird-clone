#pragma once

#include "ecs/scheduling/callable_traits.hpp"

#include <entt/entt.hpp>

template<typename T>
using component_t = std::remove_reference_t<T>;

template <typename List>
struct system_runner;

template <typename... Components>
struct system_runner<type_list<Components...>>
{
	template <typename Callable>
	static void run(
		entt::registry& registry,
		Callable&& callable
	) {
		auto view = registry.template view<component_t<Components>...>();

		for (auto& entity : view)
		{
			std::invoke(
				callable,
				view.template get<
					component_t<Components>
				>(entity)...);
		}
	}

	template <typename T, typename Callable>
	static void run_instance(
		entt::registry& registry,
		T* instance,
		Callable&& callable
	) {
		auto view = registry.template view<component_t<Components>...>();

		for (auto& entity : view)
		{
			std::invoke(
				callable,
				instance,
				view.template get<
				component_t<Components>
				>(entity)...);
		}
	}
};


