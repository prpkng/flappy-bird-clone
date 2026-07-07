#pragma once

#include <ecs/plugin.hpp>

struct RenderPlugin : public Plugin
{		
	virtual void setup(World& world) override;
};

