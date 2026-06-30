#pragma once

#include "window.hpp"
#include "SceneStager.hpp"
#include <memory>

struct SDL_Renderer;

class Application
{
public:
	Application();
	~Application();

	void Initialize();

	void Tick();
	void MainLoop();
	void OnEvent(Event& ev);
	
	void Shutdown();

	SDL_Renderer* GetRenderer() const { return renderer; }

private:
	SceneStager sceneStager;
	std::unique_ptr<Window> window;

	SDL_Renderer* renderer;
};

