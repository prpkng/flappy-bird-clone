#pragma once

#include <entt/entt.hpp>

struct KeyDownEvent;

class PlayerSystem {
public:

	PlayerSystem() = default;
	~PlayerSystem() = default;


	void on_key_down(const KeyDownEvent& event);

	void update(float delta, entt::registry& registry, entt::dispatcher& dispatcher);
};