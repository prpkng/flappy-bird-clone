#pragma once

#include <string>

enum class EventType {
    WindowClose, WindowResize,
    KeyPress, KeyRelease, KeyType,
    MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
};

class Event {
public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual std::string ToString() const { return GetName(); }

    bool IsHandled() const { return m_Handled; }

protected: 
    bool m_Handled;
};

#define EVENT_CLASS_TYPE(type) virtual EventType GetEventType() const { return EventType::type; }\
                               virtual const char* GetName() const { return #type; }

class WindowCloseEvent : public Event {
public:
    WindowCloseEvent() = default;
    EVENT_CLASS_TYPE(WindowClose)
};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(unsigned int width, unsigned int height);

    unsigned int GetWidth() const { return width; }
    unsigned int GetHeight() const { return height; }

    std::string ToString() const override;

    EVENT_CLASS_TYPE(WindowResize)
private:
    unsigned int width, height;
};

class KeyEvent : public Event {
public:
    inline unsigned int GetKeyCode() const { return keyCode; }

    KeyEvent(unsigned int keycode)
        : keyCode(keycode) {
    }

    unsigned int keyCode;
};

class KeyPressedEvent : public KeyEvent {
public:
    KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) {}

    inline int GetRepeatCount() const { return repeatCount; }

    std::string ToString() const override;
    EVENT_CLASS_TYPE(KeyPress)
private:
    int repeatCount;
};


class KeyReleasedEvent : public KeyEvent {
public:
    KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

    std::string ToString() const override;
    EVENT_CLASS_TYPE(KeyRelease)
};

constexpr auto MOUSE_BUTTON_LEFT    = 0;
constexpr auto MOUSE_BUTTON_RIGHT   = 1;
constexpr auto MOUSE_BUTTON_MIDDLE  = 2;
constexpr auto MOUSE_BUTTON_4		= 3;
constexpr auto MOUSE_BUTTON_5		= 4;


class MouseMovedEvent : public Event {
public:
    MouseMovedEvent(float x, float y)
        : mouseX(x), mouseY(y) {
    }

    inline float GetX() const { return mouseX; }
    inline float GetY() const { return mouseY; }

    std::string ToString() const override;

    EVENT_CLASS_TYPE(MouseMove)
private:
    float mouseX, mouseY;
};

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(const float xOffset, const float yOffset)
        : xOffset(xOffset), yOffset(yOffset) {
    }

    float GetXOffset() const { return xOffset; }
    float GetYOffset() const { return yOffset; }

    std::string ToString() const override;

    EVENT_CLASS_TYPE(MouseScroll)
private:
    float xOffset, yOffset;
};

class MouseButtonEvent : public Event
{
public:
    uint8_t GetMouseButton() const { return button; }

protected:
    MouseButtonEvent(const uint8_t button)
        : button(button) {
    }

    uint8_t button;
};


class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(const uint8_t button)
        : MouseButtonEvent(button) {
    }

    std::string ToString() const override;

    EVENT_CLASS_TYPE(MouseButtonPress)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(const uint8_t button)
        : MouseButtonEvent(button) {
    }

    std::string ToString() const override;

    EVENT_CLASS_TYPE(MouseButtonRelease)
};