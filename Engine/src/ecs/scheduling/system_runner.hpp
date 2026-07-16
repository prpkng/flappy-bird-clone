#pragma once

#include "ecs/scheduling/callable_traits.hpp"
#include "ecs/querying/query_building.hpp"
#include <entt/entt.hpp>

#include <Log.hpp>
#include <cxxabi.h>

template <typename T>
using component_t = std::remove_reference_t<T>;

template <typename T>
struct unwrap_with;

template <typename T>
struct unwrap_with<With<T>>
{
	using type = T;
};

inline std::string hr_type_name(const std::type_info& type) {
	int status = 0;
	auto name = type.name();
	char* output = abi::__cxa_demangle(name, nullptr, nullptr, &status);

	std::string result;
	if (status == 0) {
		result = std::string(output);
	}
	else {
		result = "Unreadable name!!";
	}
	
	std::free(output);
	return result;
}


template <typename Query>
struct system_runner;

template <typename... Components, typename... Includes, typename... Excludes,
          typename... Resources>
struct system_runner<
    query_description<type_list<Components...>, type_list<Includes...>,
                      type_list<Excludes...>, type_list<Resources...>>> {

    template <typename Callable>
    static void run(entt::registry& registry, Callable&& callable) {
        auto view =
            registry.template view<component_t<Components>..., typename unwrap_with<Includes>::type...>(
                entt::exclude<Excludes...>);

		LOG_INFO("TYPE NAME: {}", hr_type_name(typeid(view.each())));
		
		//TODO in order to fix this, we're gonna need to split EVERYTHING into passing a Query parameter (an arbitrary number of queries maybe)
		// and then parsing the With<> and Without<> as arguments of that Query
        for (auto& entity : view) {
            std::invoke(callable,
                        view.template get<component_t<Components>>(entity)...,
                        registry.ctx().template get<Resources>()...);
        }
    }

    template <typename T, typename Callable>
    static void run_instance(entt::registry& registry, T* instance,
                             Callable&& callable) {
        auto view =
            registry.template view<component_t<Components>..., Includes...>(
                entt::exclude<Excludes...>);

        for (auto& entity : view) {
            std::invoke(callable, instance,
                        view.template get<component_t<Components>>(entity)...,
                        registry.ctx().template get<Resources>()...);
        }
    }
};
