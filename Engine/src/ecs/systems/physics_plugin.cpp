#include "ecs/systems/physics_plugin.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/physics.hpp"
#include "ecs/components/player.hpp"
#include "ecs/world.hpp"
#include "ecs/system_scheduler.hpp"
#include "app/timer.hpp"

#include <SDL3/SDL.h>
#include "physics_plugin.hpp"

static void update(World& world)
{
	entt::registry& registry = world.registry;
	for (auto &&[entity, trans, obj] : 
		registry.view<Transform, const PhysicsObject>().each())
	{
		trans.position += obj.velocity * Timer::dt();
	}

}

static void debug_render(World& world)
{
	entt::registry& registry = world.registry;
	if (!registry.ctx().contains<PhysicsDebugSettings>() ||
		registry.ctx().get<PhysicsDebugSettings>().enabled == false) return;
	
	SDL_Renderer* renderer = registry.ctx().get<SDL_Renderer*>();
	auto view = registry.view<const Transform, const CollisionShape>();
	for (auto &&[entity, trans, shape] : view.each()) {

		SDL_SetRenderDrawColorFloat(renderer, 
			shape.debug_color.r, 
			shape.debug_color.g, 
			shape.debug_color.b, 
			shape.debug_color.a);

		SDL_FRect rect{ 
			trans.position.x + shape.bounding_box.x,
			trans.position.y + shape.bounding_box.y,
			shape.bounding_box.width, 
			shape.bounding_box.height 
		};
		SDL_RenderRect(renderer, &rect);

	}
}

void PhysicsPlugin::setup(World& world)
{
	world.scheduler->add_system(Schedule::Update, &update);
	world.scheduler->add_system(Schedule::Render, &debug_render);
}
