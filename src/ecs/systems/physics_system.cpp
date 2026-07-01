#include "physics_system.hpp"

#include "ecs/components/transform.hpp"
#include "ecs/components/physics.hpp"

void PhysicsSystem::update(float delta, entt::registry& registry)
{
	
}

void PhysicsSystem::debug_render(SDL_Renderer* renderer, entt::registry& registry)
{

	auto view = registry.view<const Transform, const PhysicsObject, const CollisionShape>();
	for (auto &&[entity, trans, physobj, shape] : view.each()) {




	}
}

