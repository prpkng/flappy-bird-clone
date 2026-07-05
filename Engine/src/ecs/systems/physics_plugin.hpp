#pragma once

#include "ecs/plugin.hpp"

struct PhysicsDebugSettings {
	bool enabled = false;
};

struct PhysicsPlugin : public Plugin
{
	virtual void setup(class World& world) override;
};

