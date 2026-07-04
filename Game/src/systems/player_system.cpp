#include "systems/player_system.hpp"

#include "components/parallax.hpp"

#include <ecs/events/key_events.hpp>
#include <ecs/components/player.hpp>
#include <ecs/components/transform.hpp>
#include <ecs/components/sprite.hpp>
#include <ecs/components/physics.hpp>
#include <math/math.hpp>
#include <Log.hpp>


const float JUMP_FORCE = 155.0f;
const float GRAVITY = 80.0f;
const float MAX_FALL_SPEED = 180.0f;

void PlayerSystem::on_key_down(const KeyDownEvent& event)
{
	if (event.physical_key != PhysicalKeyCode::Space) return;

	for (auto&& [entity, phys_obj] : 
		event.registry.view<PhysicsObject, const Player>().each()) {
		
		phys_obj.velocity.y = -JUMP_FORCE;
	}
}

void PlayerSystem::update(float delta, entt::registry& registry, entt::dispatcher& dispatcher)
{
	//TODO move this outta here

	for (auto&& [entity, sprite, parallax] :
		registry.view<Sprite, const Parallax>().each()) {
		if (!sprite.texture_region.has_value()) continue;

		sprite.texture_region.value().x += parallax.speed * delta;

		auto rect = sprite.texture_region.value();
		LOG_INFO("({}, {}, {}, {})", rect.x, rect.y, rect.width, rect.height);
	}

	for (auto&& [entity, obj, trans] :
		registry.view<PhysicsObject, Transform, const Player>().each())
	{
		obj.velocity.y += GRAVITY * 4 * delta;
		obj.velocity.y = MIN(obj.velocity.y, MAX_FALL_SPEED);

		// Prevent out of bounds
		trans.position.y = CLAMP(trans.position.y, 0, 255);

		trans.set_rotation_degrees(obj.velocity.y/4.0f);
	}


}
