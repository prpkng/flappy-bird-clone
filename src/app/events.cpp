#include "events.hpp"
#include <format>
#include <magic_enum/magic_enum.hpp>

WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}

std::string WindowResizeEvent::ToString() const
{
	return std::format("WindowResizeEvent: {0}x{1}", width, height);
}

std::string KeyPressedEvent::ToString() const
{
	return std::format("KeyPressedEvent: {0} [{1}] ({2} repeats)", PhysicalKey::to_string(keyCode), (int)keyCode, repeatCount);
}

std::string KeyReleasedEvent::ToString() const
{
	return std::format("KeyReleasedEvent: {0} [{1}]", PhysicalKey::to_string(keyCode), (int)keyCode);
}

std::string MouseMovedEvent::ToString() const
{
	return std::format("MouseButtonPressedEvent: {0}x{1}", mouseX, mouseY);
}

std::string MouseScrolledEvent::ToString() const
{
	return std::format("MouseButtonPressedEvent: X: {0} Y: {1}", xOffset, yOffset);
}

std::string MouseButtonPressedEvent::ToString() const
{
	const char* buttonNames[] = { "Left", "Right", "Middle", "Button4", "Button5" };
	return std::format("MouseButtonPressedEvent: {0}", buttonNames[button]);
}

std::string MouseButtonReleasedEvent::ToString() const
{
	const char* buttonNames[] = { "Left", "Right", "Middle", "Button4", "Button5" };
	return std::format("MouseButtonReleasedEvent: {0}", buttonNames[button]);
}
