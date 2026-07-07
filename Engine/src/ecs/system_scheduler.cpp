#include "world.hpp"
#include "system_scheduler.hpp"
#include <Log.hpp>


void SystemScheduler::initialize(World& world)
{
	run_schedule(Schedule::Initialize, world);
}

void SystemScheduler::update(World& world)
{
	run_schedule(Schedule::PreUpdate, world);
	run_schedule(Schedule::Update, world);
	run_schedule(Schedule::PostUpdate, world);
}

void SystemScheduler::fixed_update(World& world)
{
	run_schedule(Schedule::PreFixedUpdate, world);
	run_schedule(Schedule::FixedUpdate, world);
	run_schedule(Schedule::PostFixedUpdate, world);
}

void SystemScheduler::render(World& world)
{
	run_schedule(Schedule::PreRender, world);
	run_schedule(Schedule::Render, world);
	run_schedule(Schedule::PostRender, world);
}

void SystemScheduler::cleanup(World& world)
{
	run_schedule(Schedule::Cleanup, world);
}

void SystemScheduler::run_schedule(Schedule schedule, World& world)
{
	auto it = systems.find(schedule);

	if (it == systems.end()) return;

	for (auto& system : it->second) {
		system(world);
	}
}
