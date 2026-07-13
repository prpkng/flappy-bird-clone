#include "systems/player_system.hpp"

#include "components/parallax.hpp"

#include <app/timer.hpp>
#include <ecs/events/key_events.hpp>
#include <ecs/components/player.hpp>
#include <ecs/components/transform.hpp>
#include <ecs/components/sprite.hpp>
#include <ecs/components/physics.hpp>
#include <math/math.hpp>
#include <Log.hpp>
#include "pipe_system.hpp"
#include <ecs/world.hpp>
#include <ecs/events/event_dispatcher.hpp>
#include <ecs/system_scheduler.hpp>

const float JUMP_FORCE = 135.0f;
const float GRAVITY = 80.0f;
const float MAX_FALL_SPEED = 180.0f;

void PlayerPlugin::setup(World& world) {
	world.scheduler->add_system(Schedule::Update, this, &PlayerPlugin::update);
	world.system_dispatcher->subscribe<KeyDownEvent>(this, &PlayerPlugin::on_key_down);
}

void PlayerPlugin::on_key_down(const KeyDownEvent& event, World& world)
{
	if (event.physical_key != PhysicalKeyCode::Space) return;
	
	auto& registry = world.registry;
	for (auto&& [entity, phys_obj] : 
		registry.view<PhysicsObject, const Player>().each()) {
		
		phys_obj.velocity.y = -JUMP_FORCE;
	}
}

void PlayerPlugin::update(World& world)
{
	auto& registry = world.registry;

	for (auto&& [entity, obj, trans] :
		registry.view<PhysicsObject, Transform, const Player>().each())
	{
		obj.velocity.y += GRAVITY * 4 * Timer::dt();
		obj.velocity.y = MIN(obj.velocity.y, MAX_FALL_SPEED);

		// Prevent out of bounds
		trans.position.y = CLAMP(trans.position.y, 0, 255);

		trans.set_rotation_degrees(obj.velocity.y/4.0f);
	}


}
