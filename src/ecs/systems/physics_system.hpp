#pragma once

#include <entt/entt.hpp>

struct SDL_Renderer;

class PhysicsSystem
{
public:
	PhysicsSystem() = default;
	~PhysicsSystem() = default;
	
	void update(float delta, entt::registry& registry);

	void debug_render(SDL_Renderer* renderer, entt::registry& registry);
};

