#include "window_events.hpp"
#include <format>
#include "Log.hpp"

std::string WindowEvent::to_string() const
{
	const char* buttonNames[] = { "Left", "Right", "Middle", "Button4", "Button5" };

	switch (type) {
	case EventType::WindowClose: return "WindowCloseEvent";
	case EventType::WindowResize: return std::format("WindowResizeEvent: {0}x{1}", resize.width, resize.height);
	case EventType::KeyPress: return std::format("KeyPressedEvent: {0} [{1}] ({2} repeats)", 
		Key::to_string(key.key_code), PhysicalKey::to_string(key.physical_code), key.repeat_count);
	case EventType::KeyRelease: return std::format("KeyReleasedEvent: {0} [{1}]", 
		Key::to_string(key.key_code), PhysicalKey::to_string(key.physical_code));
	case EventType::MouseMove: return std::format("MouseButtonMovedEvent: [{0}, {1}]", mouse.xrel, mouse.yrel);
	case EventType::MouseScroll: return std::format("MouseButtonScrolldEvent: [{0}, {1}]", scroll.x, scroll.y);
	case EventType::MouseButtonPress: return std::format("MouseButtonPressedEvent: {0}", buttonNames[mouse.button-1]);
	case EventType::MouseButtonRelease: return std::format("MouseButtonReleasedEvent: {0}", buttonNames[mouse.button-1]);
	}

	LOG_FATAL("Unknown event type!");
	return "";
}
