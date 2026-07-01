#pragma once

#include "app/keys.hpp"

#include <string>

enum class EventType {
    WindowClose, WindowResize,
    KeyPress, KeyRelease, KeyType,
    MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
};

constexpr unsigned int MOUSE_BUTTON_LEFT = 1;
constexpr unsigned int MOUSE_BUTTON_RIGHT = 2;
constexpr unsigned int MOUSE_BUTTON_MIDDLE = 3;
constexpr unsigned int MOUSE_BUTTON_4 = 4;
constexpr unsigned int MOUSE_BUTTON_5 = 5;

struct WindowEvent {
    struct ResizeEvent {
        float width;
        float height;
    };

    struct MoveEvent {
        float x;
        float y;
    };

    struct KeyEvent {
        PhysicalKeyCode physical_code;
        KeyCode key_code;
        unsigned int repeat_count;
    };

    struct MouseEvent {
        float xrel;
        float yrel;
        unsigned int button;
    };

    struct ScrollEvent {
        float x;
        float y;
    };

    union {
        ResizeEvent resize;
        MoveEvent move;
        ScrollEvent scroll;
        KeyEvent key;
        MouseEvent mouse;
    };

    EventType type;
    bool handled;

    [[nodiscard]] std::string to_string() const;
};
