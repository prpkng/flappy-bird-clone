#include "physics_system.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/physics.hpp"
#include "ecs/components/player.hpp"

#include <SDL3/SDL.h>

constexpr float GRAVITY = 9.8f;

void PhysicsSystem::update(float delta, entt::registry& registry)
{

	for (auto&& [entity, obj] :
		registry.view<PhysicsObject, const Player>().each())
	{
		obj.velocity.y += GRAVITY * 4 * delta;
	}

	for (auto &&[entity, trans, obj] : 
		registry.view<Transform, const PhysicsObject>().each())
	{
		trans.position += obj.velocity * delta;
	}

}

void PhysicsSystem::debug_render(SDL_Renderer* renderer, entt::registry& registry)
{

	auto view = registry.view<const Transform, const PhysicsObject, const CollisionShape>();
	for (auto &&[entity, trans, physobj, shape] : view.each()) {

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

