#pragma once

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>

#include <string>

#include <magic_enum/magic_enum.hpp>

namespace PhysicalKey {
    enum class Code {
        Unknown = SDL_SCANCODE_UNKNOWN,

        A = SDL_SCANCODE_A,
        B = SDL_SCANCODE_B,
        C = SDL_SCANCODE_C,
        D = SDL_SCANCODE_D,
        E = SDL_SCANCODE_E,
        F = SDL_SCANCODE_F,
        G = SDL_SCANCODE_G,
        H = SDL_SCANCODE_H,
        I = SDL_SCANCODE_I,
        J = SDL_SCANCODE_J,
        K = SDL_SCANCODE_K,
        L = SDL_SCANCODE_L,
        M = SDL_SCANCODE_M,
        N = SDL_SCANCODE_N,
        O = SDL_SCANCODE_O,
        P = SDL_SCANCODE_P,
        Q = SDL_SCANCODE_Q,
        R = SDL_SCANCODE_R,
        S = SDL_SCANCODE_S,
        T = SDL_SCANCODE_T,
        U = SDL_SCANCODE_U,
        V = SDL_SCANCODE_V,
        W = SDL_SCANCODE_W,
        X = SDL_SCANCODE_X,
        Y = SDL_SCANCODE_Y,
        Z = SDL_SCANCODE_Z,

        Number1 = SDL_SCANCODE_1,
        Number2 = SDL_SCANCODE_2,
        Number3 = SDL_SCANCODE_3,
        Number4 = SDL_SCANCODE_4,
        Number5 = SDL_SCANCODE_5,
        Number6 = SDL_SCANCODE_6,
        Number7 = SDL_SCANCODE_7,
        Number8 = SDL_SCANCODE_8,
        Number9 = SDL_SCANCODE_9,
        Number0 = SDL_SCANCODE_0,

        Return = SDL_SCANCODE_RETURN,
        Escape = SDL_SCANCODE_ESCAPE,
        Backspace = SDL_SCANCODE_BACKSPACE,
        Tab = SDL_SCANCODE_TAB,
        Space = SDL_SCANCODE_SPACE,

        Minus = SDL_SCANCODE_MINUS,
        Equals = SDL_SCANCODE_EQUALS,
        Leftbracket = SDL_SCANCODE_LEFTBRACKET,
        Rightbracket = SDL_SCANCODE_RIGHTBRACKET,
        Backslash = SDL_SCANCODE_BACKSLASH, /**< Located at the lower left of the return
                                      *   key on ISO keyboards and at the right end
                                      *   of the QWERTY row on ANSI keyboards.
                                      *   Produces REVERSE SOLIDUS (backslash) and
                                      *   VERTICAL LINE in a US layout, REVERSE
                                      *   SOLIDUS and VERTICAL LINE in a UK Mac
                                      *   layout, NUMBER SIGN and TILDE in a UK
                                      *   Windows layout, DOLLAR SIGN and POUND SIGN
                                      *   in a Swiss German layout, NUMBER SIGN and
                                      *   APOSTROPHE in a German layout, GRAVE
                                      *   ACCENT and POUND SIGN in a French Mac
                                      *   layout, and ASTERISK and MICRO SIGN in a
                                      *   French Windows layout.
                                      */
        Nonushash = SDL_SCANCODE_NONUSHASH, /**< ISO USB keyboards actually use this code
                                      *   instead of 49 for the same key, but all
                                      *   OSes I've seen treat the two codes
                                      *   identically. So, as an implementer, unless
                                      *   your keyboard generates both of those
                                      *   codes and your OS treats them differently,
                                      *   you should generate SDL_SCANCODE_BACKSLASH
                                      *   instead of this code. As a user, you
                                      *   should not rely on this code because SDL
                                      *   will never generate it with most (all?)
                                      *   keyboards.
                                      */
        Semicolon = SDL_SCANCODE_SEMICOLON,
        Apostrophe = SDL_SCANCODE_APOSTROPHE,
        Grave = SDL_SCANCODE_GRAVE, /**< Located in the top left corner (on both ANSI
                                  *   and ISO keyboards). Produces GRAVE ACCENT and
                                  *   TILDE in a US Windows layout and in US and UK
                                  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                  *   and NOT SIGN in a UK Windows layout, SECTION
                                  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                  *   layouts on ISO keyboards, SECTION SIGN and
                                  *   DEGREE SIGN in a Swiss German layout (Mac:
                                  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                  *   DEGREE SIGN in a German layout (Mac: only on
                                  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                  *   French Windows layout, COMMERCIAL AT and
                                  *   NUMBER SIGN in a French Mac layout on ISO
                                  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                  *   SIGN in a Swiss German, German, or French Mac
                                  *   layout on ANSI keyboards.
                                  */
        Comma = SDL_SCANCODE_COMMA,
        Period = SDL_SCANCODE_PERIOD,
        Slash = SDL_SCANCODE_SLASH,

        Capslock = SDL_SCANCODE_CAPSLOCK,

        F1 = SDL_SCANCODE_F1,
        F2 = SDL_SCANCODE_F2,
        F3 = SDL_SCANCODE_F3,
        F4 = SDL_SCANCODE_F4,
        F5 = SDL_SCANCODE_F5,
        F6 = SDL_SCANCODE_F6,
        F7 = SDL_SCANCODE_F7,
        F8 = SDL_SCANCODE_F8,
        F9 = SDL_SCANCODE_F9,
        F10 = SDL_SCANCODE_F10,
        F11 = SDL_SCANCODE_F11,
        F12 = SDL_SCANCODE_F12,

        PrintScreen = SDL_SCANCODE_PRINTSCREEN,
        ScrollLock = SDL_SCANCODE_SCROLLLOCK,
        Pause = SDL_SCANCODE_PAUSE,
        Insert = SDL_SCANCODE_INSERT, /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        Home = SDL_SCANCODE_HOME,
        PageUp = SDL_SCANCODE_PAGEUP,
        Delete = SDL_SCANCODE_DELETE,
        End = SDL_SCANCODE_END,
        PageDown = SDL_SCANCODE_PAGEDOWN,
        Right = SDL_SCANCODE_RIGHT,
        Left = SDL_SCANCODE_LEFT,
        Down = SDL_SCANCODE_DOWN,
        Up = SDL_SCANCODE_UP,

        NumLockClear = SDL_SCANCODE_NUMLOCKCLEAR, /**< num lock on PC, clear on Mac keyboards
                                         */
        KpDivide = SDL_SCANCODE_KP_DIVIDE,
        KpMultiply = SDL_SCANCODE_KP_MULTIPLY,
        KpMinus = SDL_SCANCODE_KP_MINUS,
        KpPlus = SDL_SCANCODE_KP_PLUS,
        KpEnter = SDL_SCANCODE_KP_ENTER,
        Kp1 = SDL_SCANCODE_KP_1,
        Kp2 = SDL_SCANCODE_KP_2,
        Kp3 = SDL_SCANCODE_KP_3,
        Kp4 = SDL_SCANCODE_KP_4,
        Kp5 = SDL_SCANCODE_KP_5,
        Kp6 = SDL_SCANCODE_KP_6,
        Kp7 = SDL_SCANCODE_KP_7,
        Kp8 = SDL_SCANCODE_KP_8,
        Kp9 = SDL_SCANCODE_KP_9,
        Kp0 = SDL_SCANCODE_KP_0,
        KpPeriod = SDL_SCANCODE_KP_PERIOD,

        NonUSBackslash = SDL_SCANCODE_NONUSBACKSLASH, /**< This is the additional key that ISO
                                            *   keyboards have over ANSI ones,
                                            *   located between left shift and Z.
                                            *   Produces GRAVE ACCENT and TILDE in a
                                            *   US or UK Mac layout, REVERSE SOLIDUS
                                            *   (backslash) and VERTICAL LINE in a
                                            *   US or UK Windows layout, and
                                            *   LESS-THAN SIGN and GREATER-THAN SIGN
                                            *   in a Swiss German, German, or French
                                            *   layout. */
        Application = SDL_SCANCODE_APPLICATION, /**< windows contextual menu, compose */
        Power = SDL_SCANCODE_POWER, /**< The USB document says this is a status flag,
                                   *   not a physical key - but some Mac keyboards
                                   *   do have a power key. */
        KpEquals = SDL_SCANCODE_KP_EQUALS,
        F13 = SDL_SCANCODE_F13,
        F14 = SDL_SCANCODE_F14,
        F15 = SDL_SCANCODE_F15,
        F16 = SDL_SCANCODE_F16,
        F17 = SDL_SCANCODE_F17,
        F18 = SDL_SCANCODE_F18,
        F19 = SDL_SCANCODE_F19,
        F20 = SDL_SCANCODE_F20,
        F21 = SDL_SCANCODE_F21,
        F22 = SDL_SCANCODE_F22,
        F23 = SDL_SCANCODE_F23,
        F24 = SDL_SCANCODE_F24,
        Execute = SDL_SCANCODE_EXECUTE,
        Help = SDL_SCANCODE_HELP,    /**< AL Integrated Help Center */
        Menu = SDL_SCANCODE_MENU,    /**< Menu (show menu) */
        Select = SDL_SCANCODE_SELECT,
        Stop = SDL_SCANCODE_STOP,    /**< AC Stop */
        Again = SDL_SCANCODE_AGAIN,   /**< AC Redo/Repeat */
        Undo = SDL_SCANCODE_UNDO,    /**< AC Undo */
        Cut = SDL_SCANCODE_CUT,     /**< AC Cut */
        Copy = SDL_SCANCODE_COPY,    /**< AC Copy */
        Paste = SDL_SCANCODE_PASTE,   /**< AC Paste */
        Find = SDL_SCANCODE_FIND,    /**< AC Find */
        Mute = SDL_SCANCODE_MUTE,
        VolumeUp = SDL_SCANCODE_VOLUMEUP,
        VolumeDown = SDL_SCANCODE_VOLUMEDOWN,
        /* not sure whether there's a reason to enable these */
        /*     Lockingcapslock = SDL_SCANCODE_LOCKINGCAPSLOCK,  */
        /*     Lockingnumlock = SDL_SCANCODE_LOCKINGNUMLOCK, */
        /*     Lockingscrolllock = SDL_SCANCODE_LOCKINGSCROLLLOCK, */
        KpComma = SDL_SCANCODE_KP_COMMA,
        KpEqualsAS400 = SDL_SCANCODE_KP_EQUALSAS400,

        International1 = SDL_SCANCODE_INTERNATIONAL1, /**< used on Asian keyboards, see
                                                footnotes in USB doc */
        International2 = SDL_SCANCODE_INTERNATIONAL2,
        International3 = SDL_SCANCODE_INTERNATIONAL3, /**< Yen */
        International4 = SDL_SCANCODE_INTERNATIONAL4,
        International5 = SDL_SCANCODE_INTERNATIONAL5,
        International6 = SDL_SCANCODE_INTERNATIONAL6,
        International7 = SDL_SCANCODE_INTERNATIONAL7,
        International8 = SDL_SCANCODE_INTERNATIONAL8,
        International9 = SDL_SCANCODE_INTERNATIONAL9,
        Lang1 = SDL_SCANCODE_LANG1, /**< Hangul/English toggle */
        Lang2 = SDL_SCANCODE_LANG2, /**< Hanja conversion */
        Lang3 = SDL_SCANCODE_LANG3, /**< Katakana */
        Lang4 = SDL_SCANCODE_LANG4, /**< Hiragana */
        Lang5 = SDL_SCANCODE_LANG5, /**< Zenkaku/Hankaku */
        Lang6 = SDL_SCANCODE_LANG6, /**< reserved */
        Lang7 = SDL_SCANCODE_LANG7, /**< reserved */
        Lang8 = SDL_SCANCODE_LANG8, /**< reserved */
        Lang9 = SDL_SCANCODE_LANG9, /**< reserved */

        Alterase = SDL_SCANCODE_ALTERASE,    /**< Erase-Eaze */
        Sysreq = SDL_SCANCODE_SYSREQ,
        Cancel = SDL_SCANCODE_CANCEL,      /**< AC Cancel */
        Clear = SDL_SCANCODE_CLEAR,
        Prior = SDL_SCANCODE_PRIOR,
        RETURN2 = SDL_SCANCODE_RETURN2,
        Separator = SDL_SCANCODE_SEPARATOR,
        Out = SDL_SCANCODE_OUT,
        Oper = SDL_SCANCODE_OPER,
        Clearagain = SDL_SCANCODE_CLEARAGAIN,
        Crsel = SDL_SCANCODE_CRSEL,
        Exsel = SDL_SCANCODE_EXSEL,

        Kp00 = SDL_SCANCODE_KP_00,
        Kp000 = SDL_SCANCODE_KP_000,
        ThousandsSeparator = SDL_SCANCODE_THOUSANDSSEPARATOR,
        DecimalSeparator = SDL_SCANCODE_DECIMALSEPARATOR,
        CurrencyUnit = SDL_SCANCODE_CURRENCYUNIT,
        CurrencySubUnit = SDL_SCANCODE_CURRENCYSUBUNIT,
        KpLeftParen = SDL_SCANCODE_KP_LEFTPAREN,
        KpRightParen = SDL_SCANCODE_KP_RIGHTPAREN,
        KpLeftBrace = SDL_SCANCODE_KP_LEFTBRACE,
        KpRightBrace = SDL_SCANCODE_KP_RIGHTBRACE,
        KpTab = SDL_SCANCODE_KP_TAB,
        KpBackspace = SDL_SCANCODE_KP_BACKSPACE,
        KpA = SDL_SCANCODE_KP_A,
        KpB = SDL_SCANCODE_KP_B,
        KpC = SDL_SCANCODE_KP_C,
        KpD = SDL_SCANCODE_KP_D,
        KpE = SDL_SCANCODE_KP_E,
        KpF = SDL_SCANCODE_KP_F,
        KpXor = SDL_SCANCODE_KP_XOR,
        KpPower = SDL_SCANCODE_KP_POWER,
        KpPercent = SDL_SCANCODE_KP_PERCENT,
        KpLess = SDL_SCANCODE_KP_LESS,
        KpGreater = SDL_SCANCODE_KP_GREATER,
        KpAmpersand = SDL_SCANCODE_KP_AMPERSAND,
        KpDblampersand = SDL_SCANCODE_KP_DBLAMPERSAND,
        KpVerticalbar = SDL_SCANCODE_KP_VERTICALBAR,
        KpDblverticalbar = SDL_SCANCODE_KP_DBLVERTICALBAR,
        KpColon = SDL_SCANCODE_KP_COLON,
        KpHash = SDL_SCANCODE_KP_HASH,
        KpSpace = SDL_SCANCODE_KP_SPACE,
        KpAt = SDL_SCANCODE_KP_AT,
        KpExclam = SDL_SCANCODE_KP_EXCLAM,
        KpMemstore = SDL_SCANCODE_KP_MEMSTORE,
        KpMemrecall = SDL_SCANCODE_KP_MEMRECALL,
        KpMemclear = SDL_SCANCODE_KP_MEMCLEAR,
        KpMemadd = SDL_SCANCODE_KP_MEMADD,
        KpMemsubtract = SDL_SCANCODE_KP_MEMSUBTRACT,
        KpMemmultiply = SDL_SCANCODE_KP_MEMMULTIPLY,
        KpMemdivide = SDL_SCANCODE_KP_MEMDIVIDE,
        KpPlusminus = SDL_SCANCODE_KP_PLUSMINUS,
        KpClear = SDL_SCANCODE_KP_CLEAR,
        KpClearentry = SDL_SCANCODE_KP_CLEARENTRY,
        KpBinary = SDL_SCANCODE_KP_BINARY,
        KpOctal = SDL_SCANCODE_KP_OCTAL,
        KpDecimal = SDL_SCANCODE_KP_DECIMAL,
        KpHexadecimal = SDL_SCANCODE_KP_HEXADECIMAL,

        LCtrl = SDL_SCANCODE_LCTRL,
        LShift = SDL_SCANCODE_LSHIFT,
        LAlt = SDL_SCANCODE_LALT, /**< alt, option */
        LGui = SDL_SCANCODE_LGUI, /**< windows, command (apple), meta */
        RCtrl = SDL_SCANCODE_RCTRL,
        RShift = SDL_SCANCODE_RSHIFT,
        RAlt = SDL_SCANCODE_RALT, /**< alt gr, option */
        RGui = SDL_SCANCODE_RGUI, /**< windows, command (apple), meta */

        Mode = SDL_SCANCODE_MODE,    /**< I'm not sure if this is really not covered
                                     *   by any of the above, but since there's a
                                     *   special SDL_KMOD_MODE for it I'm adding it here
                                     */

                                     /* @} *//* Usage page 0x07 */

                                     /**
                                      *  \name Usage page 0x0C
                                      *
                                      *  These values are mapped from usage page 0x0C (USB consumer page).
                                      *
                                      *  There are way more keys in the spec than we can represent in the
                                      *  current scancode range, so pick the ones that commonly come up in
                                      *  real world usage.
                                      */
                                      /* @{ */

        Sleep = SDL_SCANCODE_SLEEP,                   /**< Sleep */
        Wake = SDL_SCANCODE_WAKE,                    /**< Wake */

        ChannelIncrement = SDL_SCANCODE_CHANNEL_INCREMENT,       /**< Channel Increment */
        ChannelDecrement = SDL_SCANCODE_CHANNEL_DECREMENT,       /**< Channel Decrement */

        MediaPlay = SDL_SCANCODE_MEDIA_PLAY,          /**< Play */
        MediaPause = SDL_SCANCODE_MEDIA_PAUSE,         /**< Pause */
        MediaRecord = SDL_SCANCODE_MEDIA_RECORD,        /**< Record */
        MediaFastForward = SDL_SCANCODE_MEDIA_FAST_FORWARD,  /**< Fast Forward */
        MediaRewind = SDL_SCANCODE_MEDIA_REWIND,        /**< Rewind */
        MediaNextTrack = SDL_SCANCODE_MEDIA_NEXT_TRACK,    /**< Next Track */
        MediaPreviousTrack = SDL_SCANCODE_MEDIA_PREVIOUS_TRACK, /**< Previous Track */
        MediaStop = SDL_SCANCODE_MEDIA_STOP,          /**< Stop */
        MediaEject = SDL_SCANCODE_MEDIA_EJECT,         /**< Eject */
        MediaPlayPause = SDL_SCANCODE_MEDIA_PLAY_PAUSE,    /**< Play / Pause */
        MediaSelect = SDL_SCANCODE_MEDIA_SELECT,        /* Media Select */

        AcNew = SDL_SCANCODE_AC_NEW,              /**< AC New */
        AcOpen = SDL_SCANCODE_AC_OPEN,             /**< AC Open */
        AcClose = SDL_SCANCODE_AC_CLOSE,            /**< AC Close */
        AcExit = SDL_SCANCODE_AC_EXIT,             /**< AC Exit */
        AcSave = SDL_SCANCODE_AC_SAVE,             /**< AC Save */
        AcPrint = SDL_SCANCODE_AC_PRINT,            /**< AC Print */
        AcProperties = SDL_SCANCODE_AC_PROPERTIES,       /**< AC Properties */

        AcSearch = SDL_SCANCODE_AC_SEARCH,           /**< AC Search */
        AcHome = SDL_SCANCODE_AC_HOME,             /**< AC Home */
        AcBack = SDL_SCANCODE_AC_BACK,             /**< AC Back */
        AcForward = SDL_SCANCODE_AC_FORWARD,          /**< AC Forward */
        AcStop = SDL_SCANCODE_AC_STOP,             /**< AC Stop */
        AcRefresh = SDL_SCANCODE_AC_REFRESH,          /**< AC Refresh */
        AcBookmarks = SDL_SCANCODE_AC_BOOKMARKS,        /**< AC Bookmarks */

        Softleft = SDL_SCANCODE_SOFTLEFT, /**< Usually situated below the display on phones and
                                          used as a multi-function feature key for selecting
                                          a software defined function shown on the bottom left
                                          of the display. */
        Softright = SDL_SCANCODE_SOFTRIGHT, /**< Usually situated below the display on phones and
                                           used as a multi-function feature key for selecting
                                           a software defined function shown on the bottom right
                                           of the display. */
        Call = SDL_SCANCODE_CALL, /**< Used for accepting phone calls. */
        EndCall = SDL_SCANCODE_ENDCALL, /**< Used for rejecting phone calls. */
    };

    __forceinline static Code from_sdl(SDL_Scancode sdl_keycode) {
        return static_cast<Code>(sdl_keycode);
    }

    std::string to_string(Code code);
}

namespace Key {

    enum class Code {
        Unknown = SDLK_UNKNOWN,
        Return = SDLK_RETURN,
        Escape = SDLK_ESCAPE,
        Backspace = SDLK_BACKSPACE,
        Tab = SDLK_TAB,
        Space = SDLK_SPACE,
        Exclaim = SDLK_EXCLAIM,
        DoubleApostrophe = SDLK_DBLAPOSTROPHE,
        Hash = SDLK_HASH,
        Dollar = SDLK_DOLLAR,
        Percent = SDLK_PERCENT,
        Ampersand = SDLK_AMPERSAND,
        Apostrophe = SDLK_APOSTROPHE,
        LeftParen = SDLK_LEFTPAREN,
        RightParen = SDLK_RIGHTPAREN,
        Asterisk = SDLK_ASTERISK,
        Plus = SDLK_PLUS,
        Comma = SDLK_COMMA,
        Minus = SDLK_MINUS,
        Period = SDLK_PERIOD,
        Slash = SDLK_SLASH,
        Number0 = SDLK_0,
        Number1 = SDLK_1,
        Number2 = SDLK_2,
        Number3 = SDLK_3,
        Number4 = SDLK_4,
        Number5 = SDLK_5,
        Number6 = SDLK_6,
        Number7 = SDLK_7,
        Number8 = SDLK_8,
        Number9 = SDLK_9,
        Colon = SDLK_COLON,
        Semicolon = SDLK_SEMICOLON,
        Less = SDLK_LESS,
        Equals = SDLK_EQUALS,
        Greater = SDLK_GREATER,
        Question = SDLK_QUESTION,
        At = SDLK_AT,
        LeftBracket = SDLK_LEFTBRACKET,
        Backslash = SDLK_BACKSLASH,
        RightBracket = SDLK_RIGHTBRACKET,
        Caret = SDLK_CARET,
        Underscore = SDLK_UNDERSCORE,
        Grave = SDLK_GRAVE,
        A = SDLK_A,
        B = SDLK_B,
        C = SDLK_C,
        D = SDLK_D,
        E = SDLK_E,
        F = SDLK_F,
        G = SDLK_G,
        H = SDLK_H,
        I = SDLK_I,
        J = SDLK_J,
        K = SDLK_K,
        L = SDLK_L,
        M = SDLK_M,
        N = SDLK_N,
        O = SDLK_O,
        P = SDLK_P,
        Q = SDLK_Q,
        R = SDLK_R,
        S = SDLK_S,
        T = SDLK_T,
        U = SDLK_U,
        V = SDLK_V,
        W = SDLK_W,
        X = SDLK_X,
        Y = SDLK_Y,
        Z = SDLK_Z,
        Leftbrace = SDLK_LEFTBRACE,
        Pipe = SDLK_PIPE,
        Rightbrace = SDLK_RIGHTBRACE,
        Tilde = SDLK_TILDE,
        Delete = SDLK_DELETE,
        Plusminus = SDLK_PLUSMINUS,
        Capslock = SDLK_CAPSLOCK,
        F1 = SDLK_F1,
        F2 = SDLK_F2,
        F3 = SDLK_F3,
        F4 = SDLK_F4,
        F5 = SDLK_F5,
        F6 = SDLK_F6,
        F7 = SDLK_F7,
        F8 = SDLK_F8,
        F9 = SDLK_F9,
        F10 = SDLK_F10,
        F11 = SDLK_F11,
        F12 = SDLK_F12,
        Printscreen = SDLK_PRINTSCREEN,
        Scrolllock = SDLK_SCROLLLOCK,
        Pause = SDLK_PAUSE,
        Insert = SDLK_INSERT,
        Home = SDLK_HOME,
        Pageup = SDLK_PAGEUP,
        End = SDLK_END,
        Pagedown = SDLK_PAGEDOWN,
        Right = SDLK_RIGHT,
        Left = SDLK_LEFT,
        Down = SDLK_DOWN,
        Up = SDLK_UP,
        NumlockClear = SDLK_NUMLOCKCLEAR,
        KpDivide = SDLK_KP_DIVIDE,
        KpMultiply = SDLK_KP_MULTIPLY,
        KpMinus = SDLK_KP_MINUS,
        KpPlus = SDLK_KP_PLUS,
        KpEnter = SDLK_KP_ENTER,
        Kp1 = SDLK_KP_1,
        Kp2 = SDLK_KP_2,
        Kp3 = SDLK_KP_3,
        Kp4 = SDLK_KP_4,
        Kp5 = SDLK_KP_5,
        Kp6 = SDLK_KP_6,
        Kp7 = SDLK_KP_7,
        Kp8 = SDLK_KP_8,
        Kp9 = SDLK_KP_9,
        Kp0 = SDLK_KP_0,
        KpPeriod = SDLK_KP_PERIOD,
        Application = SDLK_APPLICATION,
        Power = SDLK_POWER,
        KpEquals = SDLK_KP_EQUALS,
        F13 = SDLK_F13,
        F14 = SDLK_F14,
        F15 = SDLK_F15,
        F16 = SDLK_F16,
        F17 = SDLK_F17,
        F18 = SDLK_F18,
        F19 = SDLK_F19,
        F20 = SDLK_F20,
        F21 = SDLK_F21,
        F22 = SDLK_F22,
        F23 = SDLK_F23,
        F24 = SDLK_F24,
        Execute = SDLK_EXECUTE,
        Help = SDLK_HELP,
        Menu = SDLK_MENU,
        Select = SDLK_SELECT,
        Stop = SDLK_STOP,
        Again = SDLK_AGAIN,
        Undo = SDLK_UNDO,
        Cut = SDLK_CUT,
        Copy = SDLK_COPY,
        Paste = SDLK_PASTE,
        Find = SDLK_FIND,
        Mute = SDLK_MUTE,
        VolumeUp = SDLK_VOLUMEUP,
        VolumeDown = SDLK_VOLUMEDOWN,
        KpComma = SDLK_KP_COMMA,
        KpEQUALSAS400 = SDLK_KP_EQUALSAS400,
        Alterase = SDLK_ALTERASE,
        Sysreq = SDLK_SYSREQ,
        Cancel = SDLK_CANCEL,
        Clear = SDLK_CLEAR,
        Prior = SDLK_PRIOR,
        Return2 = SDLK_RETURN2,
        Separator = SDLK_SEPARATOR,
        Out = SDLK_OUT,
        Oper = SDLK_OPER,
        Clearagain = SDLK_CLEARAGAIN,
        Crsel = SDLK_CRSEL,
        Exsel = SDLK_EXSEL,
        Kp00 = SDLK_KP_00,
        Kp000 = SDLK_KP_000,
        ThousandsSeparator = SDLK_THOUSANDSSEPARATOR,
        DecimalSeparator = SDLK_DECIMALSEPARATOR,
        CurrencyUnit = SDLK_CURRENCYUNIT,
        CurrencySubunit = SDLK_CURRENCYSUBUNIT,
        KpLeftParen = SDLK_KP_LEFTPAREN,
        KpRightParen = SDLK_KP_RIGHTPAREN,
        KpLeftBrace = SDLK_KP_LEFTBRACE,
        KpRightBrace = SDLK_KP_RIGHTBRACE,
        KpTab = SDLK_KP_TAB,
        KpBackspace = SDLK_KP_BACKSPACE,
        KpA = SDLK_KP_A,
        KpB = SDLK_KP_B,
        KpC = SDLK_KP_C,
        KpD = SDLK_KP_D,
        KpE = SDLK_KP_E,
        KpF = SDLK_KP_F,
        KpXor = SDLK_KP_XOR,
        KpPower = SDLK_KP_POWER,
        KpPercent = SDLK_KP_PERCENT,
        KpLess = SDLK_KP_LESS,
        KpGreater = SDLK_KP_GREATER,
        KpAmpersand = SDLK_KP_AMPERSAND,
        KpDblampersand = SDLK_KP_DBLAMPERSAND,
        KpVerticalbar = SDLK_KP_VERTICALBAR,
        KpDblverticalbar = SDLK_KP_DBLVERTICALBAR,
        KpColon = SDLK_KP_COLON,
        KpHash = SDLK_KP_HASH,
        KpSpace = SDLK_KP_SPACE,
        KpAt = SDLK_KP_AT,
        KpExclam = SDLK_KP_EXCLAM,
        KpMemstore = SDLK_KP_MEMSTORE,
        KpMemrecall = SDLK_KP_MEMRECALL,
        KpMemclear = SDLK_KP_MEMCLEAR,
        KpMemadd = SDLK_KP_MEMADD,
        KpMemsubtract = SDLK_KP_MEMSUBTRACT,
        KpMemmultiply = SDLK_KP_MEMMULTIPLY,
        KpMemdivide = SDLK_KP_MEMDIVIDE,
        KpPlusminus = SDLK_KP_PLUSMINUS,
        KpClear = SDLK_KP_CLEAR,
        KpClearentry = SDLK_KP_CLEARENTRY,
        KpBinary = SDLK_KP_BINARY,
        KpOctal = SDLK_KP_OCTAL,
        KpDecimal = SDLK_KP_DECIMAL,
        KpHexadecimal = SDLK_KP_HEXADECIMAL,
        LCtrl = SDLK_LCTRL,
        LShift = SDLK_LSHIFT,
        LAlt = SDLK_LALT,
        LGui = SDLK_LGUI,
        RCtrl = SDLK_RCTRL,
        RShift = SDLK_RSHIFT,
        RAlt = SDLK_RALT,
        RGui = SDLK_RGUI,
        Mode = SDLK_MODE,
        Sleep = SDLK_SLEEP,
        Wake = SDLK_WAKE,
        ChannelIncrement = SDLK_CHANNEL_INCREMENT,
        ChannelDecrement = SDLK_CHANNEL_DECREMENT,
        MediaPlay = SDLK_MEDIA_PLAY,
        MediaPause = SDLK_MEDIA_PAUSE,
        MediaRecord = SDLK_MEDIA_RECORD,
        MediaFastForward = SDLK_MEDIA_FAST_FORWARD,
        MediaRewind = SDLK_MEDIA_REWIND,
        MediaNextTrack = SDLK_MEDIA_NEXT_TRACK,
        MediaPreviousTrack = SDLK_MEDIA_PREVIOUS_TRACK,
        MediaStop = SDLK_MEDIA_STOP,
        MediaEject = SDLK_MEDIA_EJECT,
        MediaPlayPause = SDLK_MEDIA_PLAY_PAUSE,
        MediaSelect = SDLK_MEDIA_SELECT,
        AcNew = SDLK_AC_NEW,
        AcOpen = SDLK_AC_OPEN,
        AcClose = SDLK_AC_CLOSE,
        AcExit = SDLK_AC_EXIT,
        AcSave = SDLK_AC_SAVE,
        AcPrint = SDLK_AC_PRINT,
        AcProperties = SDLK_AC_PROPERTIES,
        AcSearch = SDLK_AC_SEARCH,
        AcHome = SDLK_AC_HOME,
        AcBack = SDLK_AC_BACK,
        AcForward = SDLK_AC_FORWARD,
        AcStop = SDLK_AC_STOP,
        AcRefresh = SDLK_AC_REFRESH,
        AcBookmarks = SDLK_AC_BOOKMARKS,
        Softleft = SDLK_SOFTLEFT,
        Softright = SDLK_SOFTRIGHT,
        Call = SDLK_CALL,
        Endcall = SDLK_ENDCALL,
        LeftTab = SDLK_LEFT_TAB,
        Level5Shift = SDLK_LEVEL5_SHIFT,
        MultiKeyCompose = SDLK_MULTI_KEY_COMPOSE,
        LMeta = SDLK_LMETA,
        RMeta = SDLK_RMETA,
        LHyper = SDLK_LHYPER,
        RHyper = SDLK_RHYPER,
    };

    __forceinline static Code from_sdl(SDL_Keycode sdl_keycode) {
        return static_cast<Code>(sdl_keycode);
    }

    std::string to_string(Code code);

}

using PhysicalKeyCode = PhysicalKey::Code;
using KeyCode = Key::Code;