#pragma once

class World;

struct Plugin {
	virtual void setup(World& world) = 0;
};