#pragma once

#include "events.hpp"
#include <string>
#include <functional>

struct SDL_Window;

class Window
{
public:
	using EventCallbackFn = std::function<void(Event&)>;

	Window(int width, int height, std::string title = "");
	~Window();

	bool ShouldClose() const;
	void update();
	void SetEventCallback(EventCallbackFn callback) {
		eventCallbackFn = callback;
	}

	SDL_Window* GetHandle() const { return pWindow; }

private:
	std::string title;
	unsigned int width, height;
	SDL_Window* pWindow;

	bool shouldClose{};

	EventCallbackFn eventCallbackFn;
};

