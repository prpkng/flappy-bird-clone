#pragma once

#include "app/keys.hpp"
#include "ecs/events/base_event.hpp"

struct KeyDownEvent : public BaseEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
	KeyDownEvent(PhysicalKeyCode pkc, KeyCode kc) : physical_key(pkc), key_code(kc) {}
};

struct KeyUpEvent : public BaseEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
	KeyUpEvent(PhysicalKeyCode pkc, KeyCode kc) : physical_key(pkc), key_code(kc) {}
};
