#pragma once
#include <scenes/scene.hpp>
#include <ecs/systems/render_system.hpp>
#include <ecs/systems/physics_system.hpp>

#include "systems/player_system.hpp"

#include <entt/entt.hpp>

class TestScene : public Scene
{
	static const Vector2 VIEWPORT_SIZE;

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
	PhysicsSystem physics_system;
	PlayerSystem player_system;

	struct SDL_Texture* target_texture;
	bool debug_draw;
};

inline constexpr Vector2 TestScene::VIEWPORT_SIZE = Vector2(144, 256);