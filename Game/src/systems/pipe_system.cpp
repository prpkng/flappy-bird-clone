#include "systems/pipe_system.hpp"
#include "events/spawn_pipe_event.hpp"
#include "components/pipe.hpp"

#include <ecs/components/transform.hpp>
#include <ecs/components/sprite.hpp>
#include <ecs/components/renderable.hpp>
#include <ecs/components/physics.hpp>

#include <SDL3/SDL.h>


constexpr float OPENING_SIZE = 60;

constexpr float SCROLLING_SPEED = 30.0f;
constexpr float SPAWN_FREQUENCY = 4.f;
constexpr float SPAWN_MIN_Y = OPENING_SIZE+16.f;
constexpr float SPAWN_MAX_Y = 256-SPAWN_MIN_Y;

void PipeSystem::setup(SDL_Renderer* renderer, entt::dispatcher& dispatcher)
{
	dispatcher.sink<SpawnPipeEvent>().connect<&PipeSystem::spawn_pipe>(this);

	auto surface = SDL_LoadPNG("assets/pipe.png");
	pipe_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_SetTextureScaleMode(pipe_texture, SDL_SCALEMODE_NEAREST);
	SDL_SetTextureBlendMode(pipe_texture, SDL_BLENDMODE_BLEND);

	SDL_DestroySurface(surface);
}

void PipeSystem::spawn_pipe(const SpawnPipeEvent& event)
{
	LOG_INFO("Spawned pipe");
	//TODO --- NEXT: pipe collisions and game over (start again)
	float y = rng.sample(SPAWN_MIN_Y, SPAWN_MAX_Y);

	float y_scales[2] = { (y - OPENING_SIZE / 2.0f) / 16.0f, (256 - y - OPENING_SIZE / 2.0f) / 16.0f };
	float y_positions[2] = { 0.0f, y + OPENING_SIZE/2.0f };

	float cap_y_positions[2] = { y - OPENING_SIZE/2.0f - 16.f, y + OPENING_SIZE / 2.0f };

	for (int i = 0; i < 2; i++) {
		auto pipe_collision = entt::handle(event.registry, event.registry.create());
		pipe_collision.emplace<Transform>(Vector2(144.0, y_positions[i]));
		pipe_collision.emplace<PhysicsObject>();
		pipe_collision.emplace<CollisionShape>(Rect2(0.0f, 0.0f, 32.0f, y_scales[i]*16.f)
			.grow_individual(-6, -6, -2, -2));
		pipe_collision.emplace<Pipe>();

		auto pipe = entt::handle(event.registry, event.registry.create());
		pipe.emplace<Transform>(Vector2(144.0, y_positions[i]), Vector2(1.0f, y_scales[i]));
		pipe.emplace<Pipe>();
		pipe.emplace<Renderable>(5);
		pipe.emplace<Sprite>(pipe_texture, Rect2(0.0, 16.0, 32.0, 16.0));

		auto pipe_cap = entt::handle(event.registry, event.registry.create());
		pipe_cap.emplace<Transform>(Vector2(144.0, cap_y_positions[i]));
		pipe_cap.emplace<Pipe>();
		pipe_cap.emplace<Renderable>(6);
		auto& cap_spr = pipe_cap.emplace<Sprite>(pipe_texture, Rect2(0.0, 0.0, 32.0, 16.0));
		cap_spr.flip_v = i == 0;
	}
}

void PipeSystem::update(float delta, entt::registry& registry, entt::dispatcher& dispatcher) {
	static float counter = 10000;

	counter += delta;
	if (counter > SPAWN_FREQUENCY) {
		dispatcher.trigger(SpawnPipeEvent{ registry });
		counter = 0.0f;
	}


	for (auto&& [entity, transform] : registry.view<Transform, const Pipe>().each()) {
		transform.position.x -= delta * SCROLLING_SPEED;
	}
}
