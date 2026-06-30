#pragma once
#include "Scene.hpp"
#include <unordered_map>
#include <memory>

enum class GameStage {
	Menu,
	Game,
};

class Application;

class SceneStager
{
public:
	SceneStager(Application* application) : application(application) {}

	void add_scene(GameStage stage, Scene* scene);

	void change_scene(GameStage next);

	void update(float delta);
	void render(float delta);

	bool has_current_scene();
	std::unique_ptr<Scene>& get_current_scene();

private:
	GameStage current_stage{};
	std::unordered_map<GameStage, std::unique_ptr<Scene>> scenes{};
	Application* application;
};

