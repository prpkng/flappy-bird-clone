#pragma once

#include <ecs/plugin.hpp>

#include <entt/entt.hpp>
#include <xoshiro.h>


struct SpawnPipeEvent;
struct SDL_Texture;
struct SDL_Renderer;

struct PipePlugin : public Plugin {

	virtual void setup(World& world) override;

private:

	void spawn_pipe(const SpawnPipeEvent& event, World& world);

	void update(World& world);

	SDL_Texture* pipe_texture;
	xso::rng rng;
};
