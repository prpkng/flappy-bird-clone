#pragma once

#include "math/vector2.hpp"
#include "window_events.hpp"

#include <string>
#include <functional>


struct SDL_Window;

class Window
{
public:
	using EventCallbackFn = std::function<void(const WindowEvent&)>;

	Window(int width, int height, std::string title = "");
	~Window();

	bool should_close() const;
	void update();
	void set_event_callback(EventCallbackFn callback) {
		callback_function = callback;
	}

	inline const std::string& get_title() const { return title; }
	inline Vector2 size() const { return Vector2(width, height); }

	SDL_Window* get_handle() const { return window_handle; }

private:
	std::string title;
	unsigned int width, height;
	SDL_Window* window_handle;

	bool wnd_should_close{};

	EventCallbackFn callback_function;
};

