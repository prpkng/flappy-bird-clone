#pragma once

#include <entt/entt.hpp>
#include <xoshiro.h>


struct SpawnPipeEvent;
struct SDL_Texture;
struct SDL_Renderer;

class PipeSystem {
public:
	PipeSystem() = default;
	~PipeSystem() = default;

	void setup(SDL_Renderer* renderer, entt::dispatcher& dispatcher);

	void spawn_pipe(const SpawnPipeEvent& event);

	void update(float delta, entt::registry& registry, entt::dispatcher& dispatcher);

private:
	SDL_Texture* pipe_texture;
	xso::rng rng;
};