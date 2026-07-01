#pragma once
#include "scenes/scene.hpp"
#include "ecs/systems/render_system.hpp"

#include <entt/entt.hpp>

class TestScene : public Scene
{
public:
	virtual void enter() override;
	virtual void update(float delta) override;
	virtual void render(float delta) override;
	virtual void on_event(const WindowEvent& event) override;
	virtual void exit() override;

private:
	entt::registry registry;
	entt::dispatcher dispatcher;

	RenderSystem render_system;
};

