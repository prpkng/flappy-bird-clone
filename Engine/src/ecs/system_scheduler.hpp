#pragma once
#include "ecs/world.hpp"

#include <entt/entt.hpp>

#include <functional>
#include <cstdint>


#pragma region TEMPLATES & TRAITS

// This trait defines the arguments of the system function passed to add_system calls
template<typename>
struct system_function_traits;

// -> overload for function pointers of type  "add_system(&function)"
template<typename ReturnValue, typename... Args>
struct system_function_traits<ReturnValue(*)(Args...)>
{
	using args = std::tuple<Args...>;
	using first_arg = typename std::tuple_element_t<0, std::tuple<Args...>>;
};

// -> overload for function references of type "add_system(function)"
template<typename ReturnValue, typename... Args>
struct system_function_traits<ReturnValue(&)(Args...)>
{
	using args = std::tuple<Args...>;
	using first_arg = typename std::tuple_element_t<0, std::tuple<Args...>>;
};

// -> overload for lambdas and member functions
template<typename Class, typename ReturnValue, typename... Args>
struct system_function_traits<ReturnValue(Class::*)(Args...) const>
{
	using args = std::tuple<Args...>;
	using first_arg = typename std::tuple_element_t<0, std::tuple<Args...>>;
};

template<typename T>
using component_t = std::remove_reference_t<T>;

// Requires the first argument to be of type "World&" in order for it to be considered
// a "registry system"
template <typename Func>
concept WorldSystem = 
    std::is_same_v<std::decay_t<typename system_function_traits<std::decay_t<Func>>::first_arg>, World>;


#pragma endregion 


class SystemScheduler {
public:
	//TODO custom system class instead of std::function
	using System = std::function<void(World&)>;

	template <typename Func>
	requires(!WorldSystem<Func>)
	void add_system(Schedule schedule, Func&& func);

	template<typename Func>
	requires(WorldSystem<Func>)
	void add_system(Schedule schedule, Func&& func);


	void initialize(World& world);
	void update(World& world);
	void fixed_update(World& world);
	void render(World& world);
	void cleanup(World& world);

private:
	void run_schedule(Schedule schedule, World& world);
	
	std::unordered_map<Schedule, std::vector<System>> systems;


private:
	template <typename Tuple, std::size_t... I>
	static auto make_view(entt::registry& registry, std::index_sequence<I...>);

	template <typename Tuple, typename View, typename Func, std::size_t... I>
	static void invoke_system(View& view, entt::entity entity, Func&& func, std::index_sequence<I...>);

	template <typename Func>
	static void run_system(entt::registry& registry, Func&& func);
};

template<typename Func>
requires(WorldSystem<Func>)
inline void SystemScheduler::add_system(Schedule schedule, Func&& func)
{
	systems[schedule].push_back(
		[func]
		(World& world)
		{
			func(world);
		}
	);
}


template<typename Func>
requires(!WorldSystem<Func>)
inline void SystemScheduler::add_system(Schedule schedule, Func&& func)
{
	systems[schedule].push_back(
		[func = std::forward<Func>(func)]
		(World& world)
		{
			run_system(world.registry, func);
		}
	);
}

template<typename Tuple, std::size_t ...I>
inline auto SystemScheduler::make_view(entt::registry& registry, std::index_sequence<I...>)
{
	return registry.view<component_t<std::tuple_element_t<I, Tuple>>...>();
}

template<typename Tuple, typename View, typename Func, std::size_t ...I>
inline void SystemScheduler::invoke_system(View& view, entt::entity entity, Func&& func, std::index_sequence<I...>)
{
	func(
		view.template get<
		    component_t<
		        std::tuple_element_t<I, Tuple>
			>
		>(entity)...
	);
}

template<typename Func>
inline void SystemScheduler::run_system(entt::registry& registry, Func&& func)
{
	using args = typename system_function_traits<
		std::decay_t<Func>
	>::args;

	constexpr auto N = std::tuple_size_v<args>;

	auto view = make_view<args>(
		registry, 
		std::make_index_sequence<N>{}
	);

	for (auto entity : view) {
		invoke_system<args>(
			view,
			entity,
			func,
			std::make_index_sequence<N>{}
		);
	}
}
