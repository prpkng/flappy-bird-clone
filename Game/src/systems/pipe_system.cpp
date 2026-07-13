#include "systems/pipe_system.hpp"
#include "events/spawn_pipe_event.hpp"
#include "components/pipe.hpp"

#include <app/timer.hpp>
#include <ecs/components/transform.hpp>
#include <ecs/components/sprite.hpp>
#include <ecs/components/renderable.hpp>
#include <ecs/components/physics.hpp>
#include <ecs/world.hpp>
#include <ecs/system_scheduler.hpp>
#include <ecs/scheduling/event_dispatcher.hpp>


#include <SDL3/SDL.h>


constexpr float OPENING_SIZE = 60;

constexpr float SCROLLING_SPEED = 30.0f;
constexpr float SPAWN_FREQUENCY = 4.f;
constexpr float SPAWN_MIN_Y = OPENING_SIZE+16.f;
constexpr float SPAWN_MAX_Y = 256-SPAWN_MIN_Y;

void PipePlugin::setup(World& world)
{
	// world.dispatcher.sink<SpawnPipeEvent>().connect<&PipePlugin::spawn_pipe>(this);

	auto renderer = world.registry.ctx().get<SDL_Renderer*>();

	auto surface = SDL_LoadPNG("assets/pipe.png");
	pipe_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_SetTextureScaleMode(pipe_texture, SDL_SCALEMODE_NEAREST);
	SDL_SetTextureBlendMode(pipe_texture, SDL_BLENDMODE_BLEND);

	SDL_DestroySurface(surface);

	world.scheduler->add_system(Schedule::Update, this, &PipePlugin::update);
	world.system_dispatcher->subscribe<SpawnPipeEvent>([this](const SpawnPipeEvent& event, World& world) {
		spawn_pipe(event, world);
	});
}

void PipePlugin::spawn_pipe(const SpawnPipeEvent& event, World& world)
{
	auto& registry = world.registry;
	LOG_INFO("Spawned pipe");
	//TODO --- NEXT: pipe collisions and game over (start again)
	float y = rng.sample(SPAWN_MIN_Y, SPAWN_MAX_Y);

	float y_scales[2] = { (y - OPENING_SIZE / 2.0f) / 16.0f, (256 - y - OPENING_SIZE / 2.0f) / 16.0f };
	float y_positions[2] = { 0.0f, y + OPENING_SIZE/2.0f };

	float cap_y_positions[2] = { y - OPENING_SIZE/2.0f - 16.f, y + OPENING_SIZE / 2.0f };

	for (int i = 0; i < 2; i++) {
		auto pipe_collision = entt::handle(registry, registry.create());
		pipe_collision.emplace<Transform>(Vector2(144.0, y_positions[i]));
		pipe_collision.emplace<PhysicsObject>();
		pipe_collision.emplace<CollisionShape>(Rect2(0.0f, 0.0f, 32.0f, y_scales[i]*16.f)
			.grow_individual(-6, -6, -2, -2));
		pipe_collision.emplace<Pipe>();

		auto pipe = entt::handle(registry, registry.create());
		pipe.emplace<Transform>(Vector2(144.0, y_positions[i]), Vector2(1.0f, y_scales[i]));
		pipe.emplace<Pipe>();
		pipe.emplace<Renderable>(5);
		pipe.emplace<Sprite>(pipe_texture, Rect2(0.0, 16.0, 32.0, 16.0));

		auto pipe_cap = entt::handle(registry, registry.create());
		pipe_cap.emplace<Transform>(Vector2(144.0, cap_y_positions[i]));
		pipe_cap.emplace<Pipe>();
		pipe_cap.emplace<Renderable>(6);
		auto& cap_spr = pipe_cap.emplace<Sprite>(pipe_texture, Rect2(0.0, 0.0, 32.0, 16.0));
		cap_spr.flip_v = i == 0;
	}
}

void PipePlugin::update(World& world) {
	static float counter = 10000;

	counter += Timer::dt();
	if (counter > SPAWN_FREQUENCY) {
		world.system_dispatcher->dispatch(SpawnPipeEvent{});
		counter = 0.0f;
	}


	for (auto&& [entity, transform] : world.registry.view<Transform, const Pipe>().each()) {
		transform.position.x -= Timer::dt() * SCROLLING_SPEED;
	}
}
