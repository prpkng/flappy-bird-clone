#include "app/application.hpp"
#include "app/app_builder.hpp"

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
	if (!renderer) {
        LOG_FATAL("Renderer Creation Failed: {}", SDL_GetError());
        SDL_DestroyWindow(window->get_handle());
        SDL_Quit();
		abort();
    }
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_SetRenderVSync(renderer, 0);
}

void Application::tick() {
	window->update();

	Timer::instance()->update();

	//TODO improved timing class


	scene_stager.update(Timer::dt());

	scene_stager.render(Timer::dt());
	

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
	scene_stager.on_event(ev);
}

void Application::shutdown() {
	SDL_DestroyRenderer(renderer);
}