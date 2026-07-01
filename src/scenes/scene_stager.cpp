#include "scenes/scene_stager.hpp"

#include "app/window_events.hpp"

void SceneStager::add_scene(GameStage stage, std::unique_ptr<Scene> scene) {
	if (scenes.contains(stage)) {
		throw std::exception("stage already exists!");
	}
	if (scenes.size() == 0) current_stage = stage;
	scene->application = application;
	scenes[stage] = std::move(scene);
	get_current_scene()->enter();
}

void SceneStager::change_scene(GameStage next)
{
	if (!scenes.contains(next)) {
		throw std::exception("trying to switch to an unavailable scene!");
	}
	get_current_scene()->exit();
	current_stage = next;
	get_current_scene()->enter();
}

void SceneStager::update(float delta)
{
	if (!has_current_scene()) return;
	get_current_scene()->update(delta);
}

void SceneStager::render(float delta)
{
	if (!has_current_scene()) return;
	get_current_scene()->render(delta);
}

void SceneStager::on_event(const WindowEvent& wnd_event) 
{
	if (!has_current_scene()) return;
	get_current_scene()->on_event(wnd_event);
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
