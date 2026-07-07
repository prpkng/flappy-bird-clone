#pragma once

class World;

struct Plugin {
	Plugin() = default;
	virtual ~Plugin() = default;

	virtual void setup(World& world) = 0;
};