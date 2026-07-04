#pragma once

#include "app/keys.hpp"
#include "ecs/events/base_event.hpp"

struct KeyDownEvent : public BaseEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
};

struct KeyUpEvent : public BaseEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
};