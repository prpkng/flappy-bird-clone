#include "SceneStager.hpp"

void SceneStager::add_scene(GameStage stage, Scene* scene) {
	if (scenes.contains(stage)) {
		throw std::exception("stage already exists!");
	}
	if (scenes.size() == 0) current_stage = stage;
	scene->application = application;
	scenes[stage] = std::unique_ptr<Scene>(scene);
	get_current_scene()->OnEnter();
}

void SceneStager::change_scene(GameStage next)
{
	if (!scenes.contains(next)) {
		throw std::exception("trying to switch to an unavailable scene!");
	}
	get_current_scene()->OnExit();
	current_stage = next;
	get_current_scene()->OnEnter();
}

void SceneStager::update(float delta)
{
	get_current_scene()->update(delta);
}

void SceneStager::render(float delta)
{
	get_current_scene()->render(delta);
}

bool SceneStager::has_current_scene() {
	return scenes.contains(current_stage);
}

std::unique_ptr<Scene>& SceneStager::get_current_scene()
{
	if (!scenes.contains(current_stage)) {
		throw std::exception("current scene missing!");
	}
	return scenes.at(current_stage);
}
