#include "ecs/world.hpp"
#include <ecs/system_scheduler.hpp>

World::World() {
	scheduler = new SystemScheduler();
}

World::~World() {
	delete scheduler;
	for (auto* plugin : plugins)
		delete plugin;
}

void World::initialize()
{
	scheduler->initialize(*this);
}

void World::update(float delta) 
{
	scheduler->update(*this);
	//TODO fixed update
}

void World::render(float delta)
{
	scheduler->render(*this);
}

void World::cleanup()
{
	scheduler->cleanup(*this);
}
