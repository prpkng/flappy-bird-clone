#include "window.hpp"

#include <SDL3/SDL.h>

Window::Window(int width, int height, std::string title) : width(width), height(height), title(title)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw std::exception("Failed to init SDL3!");


	window_handle = SDL_CreateWindow(title.c_str(), width, height, 0);

	if (window_handle == nullptr)
		throw std::exception("Failed to create SDL window");
}

Window::~Window()
{
	SDL_DestroyWindow(window_handle);
	SDL_Quit();
}

bool Window::should_close() const
{
	return wnd_should_close;
}

void Window::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		WindowEvent we{};
		switch (e.type) {
		case SDL_EVENT_QUIT:
			we.type = EventType::WindowClose;
			wnd_should_close = true;
			callback_function(we);
			break;
		case SDL_EVENT_KEY_DOWN:
			we.type = EventType::KeyPress; 
			we.key.physical_code = PhysicalKey::from_sdl(e.key.scancode);
			we.key.key_code = Key::from_sdl(e.key.key); // TODO implement repeatCount
			callback_function(we);
			break;
		case SDL_EVENT_KEY_UP:
			we.type = EventType::KeyRelease; 
			we.key.physical_code = PhysicalKey::from_sdl(e.key.scancode);
			we.key.key_code = Key::from_sdl(e.key.key);
			callback_function(we);
			break;
		case SDL_EVENT_MOUSE_MOTION:
			we.type = EventType::MouseMove; 
			we.mouse.xrel = e.motion.xrel;
			we.mouse.yrel = e.motion.yrel;
			callback_function(we);
			break;
		case SDL_EVENT_MOUSE_WHEEL:
			we.type = EventType::MouseScroll;
			we.scroll.x = e.wheel.x;
			we.scroll.y = e.wheel.y;
			callback_function(we);
			break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			we.type = EventType::MouseButtonPress; 
			switch (e.button.button) {
			case SDL_BUTTON_LEFT: we.mouse.button = MOUSE_BUTTON_LEFT; break;
			case SDL_BUTTON_RIGHT: we.mouse.button = MOUSE_BUTTON_RIGHT; break;
			case SDL_BUTTON_MIDDLE: we.mouse.button = MOUSE_BUTTON_MIDDLE; break;
			case SDL_BUTTON_X1: we.mouse.button = MOUSE_BUTTON_4; break;
			case SDL_BUTTON_X2: we.mouse.button = MOUSE_BUTTON_5; break;
			}
			callback_function(we);
			break;
		case SDL_EVENT_MOUSE_BUTTON_UP:
			we.type = EventType::MouseButtonRelease;
			switch (e.button.button) {
			case SDL_BUTTON_LEFT: we.mouse.button = MOUSE_BUTTON_LEFT; break;
			case SDL_BUTTON_RIGHT: we.mouse.button = MOUSE_BUTTON_RIGHT; break;
			case SDL_BUTTON_MIDDLE: we.mouse.button = MOUSE_BUTTON_MIDDLE; break;
			case SDL_BUTTON_X1: we.mouse.button = MOUSE_BUTTON_4; break;
			case SDL_BUTTON_X2: we.mouse.button = MOUSE_BUTTON_5; break;
			}
			callback_function(we);
			break;
		}

	}
}

