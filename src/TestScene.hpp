#pragma once
#include "scenes/scene.hpp"

#include <entt/entt.hpp>

class TestScene : public Scene
{
public:
	virtual void OnEnter() override;
	virtual void update(float delta) override;
	virtual void render(float delta) override;
	virtual void OnExit() override;

private:
	entt::registry* registry;
};

