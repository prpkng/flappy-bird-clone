#include "app/application.hpp"
#include "app/app_builder.hpp"

#include "Testscene.hpp"
#include "Log.hpp"


#include <SDL3/SDL.h>

Application::Application() : scene_stager(this)
{
}

Application::~Application()
{
}

void Application::initialize(const AppConfig& config)
{
	LOG_INFO("Initializing logger...");

	window = std::make_unique<Window>(config.width, config.height, config.title);
	window->set_event_callback([this](const WindowEvent& ev) { on_event(ev); });

	renderer = SDL_CreateRenderer(window->get_handle(), NULL);
	SDL_SetRenderVSync(renderer, 0);
}

void Application::tick() {
	window->update();

	static uint64_t lastTicks = 0;
	uint64_t ticks = SDL_GetTicks();
	float delta = (ticks - lastTicks) / 1000.0;
	lastTicks = ticks;
	//TODO improved timing class


	scene_stager.update(delta);

	scene_stager.render(delta);


	SDL_RenderPresent(renderer);
}

void Application::main_loop()
{
	while (!window->should_close()) {
		tick();
	}
}

void Application::on_event(const WindowEvent& ev)
{
	LOG_INFO("Event info: {0}", ev.to_string());
}

void Application::shutdown() {
	SDL_DestroyRenderer(renderer);
}