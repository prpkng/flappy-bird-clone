#pragma once

#include "app/window.hpp"
#include "scenes/scene_stager.hpp"

#include <memory>

struct AppConfig;
struct SDL_Renderer;

class Application
{
public:
	Application();
	~Application();

	void initialize(const AppConfig& config);

	void tick();
	void main_loop();
	void on_event(Event& ev);
	
	void shutdown();

	[[nodiscard]] SDL_Renderer* get_renderer() const { return renderer; }
	[[nodiscard]] std::unique_ptr<Window>& get_window() { return window; }
	[[nodiscard]] SceneStager& get_stager() { return scene_stager; }
private:
	SceneStager scene_stager;
	std::unique_ptr<Window> window;

	SDL_Renderer* renderer;
};

