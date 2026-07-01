#pragma once

#include "app/keys.hpp"

struct KeyDownEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
};

struct KeyUpEvent {
	PhysicalKeyCode physical_key;
	KeyCode key_code;
};