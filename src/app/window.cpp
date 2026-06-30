#include "window.hpp"

#include <SDL3/SDL.h>

Window::Window(int width, int height, std::string title) : width(width), height(height), title(title)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw std::exception("Failed to init SDL3!");


	pWindow = SDL_CreateWindow(title.c_str(), width, height, 0);

	if (pWindow == nullptr)
		throw std::exception("Failed to create SDL window");
}

Window::~Window()
{
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

bool Window::ShouldClose() const
{
	return shouldClose;
}

void Window::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_EVENT_QUIT:
		{
			auto event = WindowCloseEvent();
			shouldClose = true;
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_KEY_DOWN:
		{
			auto event = KeyPressedEvent(PhysicalKey::from_sdl(e.key.scancode), 0); // TODO implement repeatCount
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_KEY_UP:
		{
			auto event = KeyReleasedEvent(PhysicalKey::from_sdl(e.key.scancode));
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_MOUSE_MOTION:
		{
			auto event = MouseMovedEvent(e.motion.xrel, e.motion.yrel);
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_MOUSE_WHEEL:
		{
			auto event = MouseScrolledEvent(e.wheel.x, e.wheel.y);
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		{
			auto event = MouseButtonPressedEvent(e.button.button);
			eventCallbackFn(event);
			break;
		}
		case SDL_EVENT_MOUSE_BUTTON_UP:
		{
			auto event = MouseButtonReleasedEvent(e.button.button);
			eventCallbackFn(event);
			break;
		}
		}

	}
}

