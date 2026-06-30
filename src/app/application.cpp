#include "application.hpp"
#include "TestScene.hpp"
#include <SDL3/SDL.h>
#include "Log.hpp"

Application::Application() : sceneStager(this)
{
}

Application::~Application()
{
}

void Application::Initialize()
{
	LOG_INFO("Initializing logger...");

	window = std::make_unique<Window>(1280, 720, "Test Window");
	window->SetEventCallback([this](Event& ev) { OnEvent(ev); });

	sceneStager.add_scene(GameStage::Game, new TestScene());

	renderer = SDL_CreateRenderer(window->GetHandle(), NULL);
	SDL_SetRenderVSync(renderer, 0);
	

	MainLoop();
}

void Application::Tick() {
	window->update();

	static uint64_t lastTicks = 0;
	uint64_t ticks = SDL_GetTicks();
	float delta = (ticks - lastTicks) / 1000.0;
	lastTicks = ticks;
	//TODO improved timing class


	sceneStager.update(delta);

	sceneStager.render(delta);


	SDL_RenderPresent(renderer);
}

void Application::MainLoop()
{
	while (!window->ShouldClose()) {
		Tick();
	}
}

void Application::OnEvent(Event& ev)
{
}

void Application::Shutdown() {
	SDL_DestroyRenderer(renderer);
}