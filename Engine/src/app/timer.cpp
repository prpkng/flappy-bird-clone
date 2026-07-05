#include "app/timer.hpp"

#include <SDL3/SDL.h>

Timer* Timer::instance() {
	static Timer instance{};
	return &instance;
}

void Timer::update() {
	float time = SDL_GetTicks() / 1000.0f;
	delta = time - current_time;
	current_time = time;
}