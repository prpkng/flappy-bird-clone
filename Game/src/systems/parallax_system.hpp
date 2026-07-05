#pragma once

#include "ecs/plugin.hpp"

struct ParallaxPlugin : public Plugin {
	virtual void setup(World& world) override;
};