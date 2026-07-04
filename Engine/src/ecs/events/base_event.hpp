#pragma once

#include <entt/entt.hpp>

struct BaseEvent { // Events must include registry!
	entt::registry& registry;
};