#pragma once
#include "ecs/world.hpp"
#include "ecs/scheduling/callable_traits.hpp"

#include <entt/entt.hpp>

#include <functional>
#include <cstdint>


template<typename T>
using component_t = std::remove_reference_t<T>;

class SystemScheduler {
public:
	//TODO custom system class instead of std::function
	using System = std::function<void(World&)>;

	template <typename Func>
	void add_system(Schedule schedule, Func&& func);

	template <typename T, typename Func>
	void add_system(Schedule schedule, T* instance, Func&& func);

	void initialize(World& world);
	void update(World& world);
	void fixed_update(World& world);
	void render(World& world);
	void cleanup(World& world);

private:
	void run_schedule(Schedule schedule, World& world);
	
	std::unordered_map<Schedule, std::vector<System>> systems;

};

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



template<typename Func>
inline void SystemScheduler::add_system(Schedule schedule, Func&& func)
{
	using traits = callable_traits<std::decay_t<Func>>;
	using args = typename traits::args;

	if constexpr (
		std::is_same_v<
			std::remove_cvref_t<
				first_type_t<args>
			>, 
			World
		>)
	{
		systems[schedule].push_back(
			[func]
			(World& world)
			{
				func(world);
			}
		);
		return;
	}


	constexpr std::size_t num_args = traits::arity;

	systems[schedule].push_back(
		[func = std::forward<Func>(func)]
		(World& world)
		{
			system_runner<args>::run(world.registry, func);
		}
	);
}

template<typename T, typename Func>
inline void SystemScheduler::add_system(Schedule schedule, T* instance, Func&& func)
{
	using traits = callable_traits<std::decay_t<Func>>;
	using args = typename traits::args;

	if constexpr (
		std::is_same_v<
		std::remove_cvref_t<
		first_type_t<args>
		>,
		World
		>)
	{
		systems[schedule].push_back(
			[instance, func]
			(World& world)
			{	
				std::invoke(func, instance, world);
			}
		);
		return;
	}


	constexpr std::size_t num_args = traits::arity;

	systems[schedule].push_back(
		[instance, func = std::forward<Func>(func)]
		(World& world)
		{
			system_runner<args>::run_instance(world.registry, instance, func);
		}
	);
}