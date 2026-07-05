#include "parallax_system.hpp"

#include <ecs/components/sprite.hpp>
#include <ecs/world.hpp>
#include <ecs/system_scheduler.hpp>
#include <app/timer.hpp>

#include "components/parallax.hpp"


static void update(Sprite& sprite, const Parallax& parallax) {
	if (!sprite.texture_region.has_value()) return;
	sprite.texture_region.value().x += parallax.speed * Timer::dt(); //TODO implement delta
}

void ParallaxPlugin::setup(World& world)
{
	world.scheduler->add_system(Schedule::Update, &update);
}
