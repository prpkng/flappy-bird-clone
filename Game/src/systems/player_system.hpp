#pragma once

#include <ecs/plugin.hpp>

#include <entt/entt.hpp>

struct KeyDownEvent;

class PlayerPlugin : public Plugin{
public:
	PlayerPlugin() = default;
	~PlayerPlugin() = default;

	virtual void setup(World& world) override;

	void on_key_down(const KeyDownEvent& event, World& world);
};
