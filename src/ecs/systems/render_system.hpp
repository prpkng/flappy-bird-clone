#pragma once

#include <entt/entt.hpp>

struct SDL_Renderer;

class RenderSystem
{
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	void render(SDL_Renderer* renderer, entt::registry& registry);
};

