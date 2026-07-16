#include "systems/player_system.hpp"

#include "components/parallax.hpp"

#include "pipe_system.hpp"
#include <Log.hpp>
#include <app/timer.hpp>
#include <ecs/components/physics.hpp>
#include <ecs/components/player.hpp>
#include <ecs/components/sprite.hpp>
#include <ecs/components/transform.hpp>
#include <ecs/events/event_dispatcher.hpp>
#include <ecs/events/key_events.hpp>
#include <ecs/system_scheduler.hpp>
#include <ecs/world.hpp>
#include <math/math.hpp>

const float JUMP_FORCE = 135.0f;
const float GRAVITY = 80.0f;
const float MAX_FALL_SPEED = 180.0f;


static void update(PhysicsObject& obj, Transform& trans, With<Player>) {
    obj.velocity.y += GRAVITY * 4 * Timer::dt();
    obj.velocity.y = MIN(obj.velocity.y, MAX_FALL_SPEED);

    // Prevent out of bounds
    trans.position.y = CLAMP(trans.position.y, 0, 255);

    trans.set_rotation_degrees(obj.velocity.y / 4.0f);
}



void PlayerPlugin::setup(World& world) {
    world.scheduler->add_system(Schedule::Update, &update);
    world.system_dispatcher->subscribe<KeyDownEvent>(
        this, &PlayerPlugin::on_key_down);
}

void PlayerPlugin::on_key_down(const KeyDownEvent& event, World& world) {
    if (event.physical_key != PhysicalKeyCode::Space)
        return;

    auto& registry = world.registry;
    for (auto&& [entity, phys_obj] :
         registry.view<PhysicsObject, const Player>().each()) {

        phys_obj.velocity.y = -JUMP_FORCE;
    }
}

