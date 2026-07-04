#include "app/keys.hpp"

#include "error/assertions.hpp"

std::string PhysicalKey::to_string(Code code)
{
	std::string text = "";
	switch (code) {
		case Code::Unknown:
			text = "Unknown";
			break;
		case Code::A:
			text = "A";
			break;
		case Code::B:
			text = "B";
			break;
		case Code::C:
			text = "C";
			break;
		case Code::D:
			text = "D";
			break;
		case Code::E:
			text = "E";
			break;
		case Code::F:
			text = "F";
			break;
		case Code::G:
			text = "G";
			break;
		case Code::H:
			text = "H";
			break;
		case Code::I:
			text = "I";
			break;
		case Code::J:
			text = "J";
			break;
		case Code::K:
			text = "K";
			break;
		case Code::L:
			text = "L";
			break;
		case Code::M:
			text = "M";
			break;
		case Code::N:
			text = "N";
			break;
		case Code::O:
			text = "O";
			break;
		case Code::P:
			text = "P";
			break;
		case Code::Q:
			text = "Q";
			break;
		case Code::R:
			text = "R";
			break;
		case Code::S:
			text = "S";
			break;
		case Code::T:
			text = "T";
			break;
		case Code::U:
			text = "U";
			break;
		case Code::V:
			text = "V";
			break;
		case Code::W:
			text = "W";
			break;
		case Code::X:
			text = "X";
			break;
		case Code::Y:
			text = "Y";
			break;
		case Code::Z:
			text = "Z";
			break;
		case Code::Number1:
			text = "Number1";
			break;
		case Code::Number2:
			text = "Number2";
			break;
		case Code::Number3:
			text = "Number3";
			break;
		case Code::Number4:
			text = "Number4";
			break;
		case Code::Number5:
			text = "Number5";
			break;
		case Code::Number6:
			text = "Number6";
			break;
		case Code::Number7:
			text = "Number7";
			break;
		case Code::Number8:
			text = "Number8";
			break;
		case Code::Number9:
			text = "Number9";
			break;
		case Code::Number0:
			text = "Number0";
			break;
		case Code::Return:
			text = "Return";
			break;
		case Code::Escape:
			text = "Escape";
			break;
		case Code::Backspace:
			text = "Backspace";
			break;
		case Code::Tab:
			text = "Tab";
			break;
		case Code::Space:
			text = "Space";
			break;
		case Code::Minus:
			text = "Minus";
			break;
		case Code::Equals:
			text = "Equals";
			break;
		case Code::Leftbracket:
			text = "Leftbracket";
			break;
		case Code::Rightbracket:
			text = "Rightbracket";
			break;
		case Code::Backslash:
			text = "Backslash";
			break;
		case Code::Nonushash:
			text = "Nonushash";
			break;
		case Code::Semicolon:
			text = "Semicolon";
			break;
		case Code::Apostrophe:
			text = "Apostrophe";
			break;
		case Code::Grave:
			text = "Grave";
			break;
		case Code::Comma:
			text = "Comma";
			break;
		case Code::Period:
			text = "Period";
			break;
		case Code::Slash:
			text = "Slash";
			break;
		case Code::Capslock:
			text = "Capslock";
			break;
		case Code::F1:
			text = "F1";
			break;
		case Code::F2:
			text = "F2";
			break;
		case Code::F3:
			text = "F3";
			break;
		case Code::F4:
			text = "F4";
			break;
		case Code::F5:
			text = "F5";
			break;
		case Code::F6:
			text = "F6";
			break;
		case Code::F7:
			text = "F7";
			break;
		case Code::F8:
			text = "F8";
			break;
		case Code::F9:
			text = "F9";
			break;
		case Code::F10:
			text = "F10";
			break;
		case Code::F11:
			text = "F11";
			break;
		case Code::F12:
			text = "F12";
			break;
		case Code::PrintScreen:
			text = "PrintScreen";
			break;
		case Code::ScrollLock:
			text = "ScrollLock";
			break;
		case Code::Pause:
			text = "Pause";
			break;
		case Code::Insert:
			text = "Insert";
			break;
		case Code::Home:
			text = "Home";
			break;
		case Code::PageUp:
			text = "PageUp";
			break;
		case Code::Delete:
			text = "Delete";
			break;
		case Code::End:
			text = "End";
			break;
		case Code::PageDown:
			text = "PageDown";
			break;
		case Code::Right:
			text = "Right";
			break;
		case Code::Left:
			text = "Left";
			break;
		case Code::Down:
			text = "Down";
			break;
		case Code::Up:
			text = "Up";
			break;
		case Code::NumLockClear:
			text = "NumLockClear";
			break;
		case Code::KpDivide:
			text = "KpDivide";
			break;
		case Code::KpMultiply:
			text = "KpMultiply";
			break;
		case Code::KpMinus:
			text = "KpMinus";
			break;
		case Code::KpPlus:
			text = "KpPlus";
			break;
		case Code::KpEnter:
			text = "KpEnter";
			break;
		case Code::Kp1:
			text = "Kp1";
			break;
		case Code::Kp2:
			text = "Kp2";
			break;
		case Code::Kp3:
			text = "Kp3";
			break;
		case Code::Kp4:
			text = "Kp4";
			break;
		case Code::Kp5:
			text = "Kp5";
			break;
		case Code::Kp6:
			text = "Kp6";
			break;
		case Code::Kp7:
			text = "Kp7";
			break;
		case Code::Kp8:
			text = "Kp8";
			break;
		case Code::Kp9:
			text = "Kp9";
			break;
		case Code::Kp0:
			text = "Kp0";
			break;
		case Code::KpPeriod:
			text = "KpPeriod";
			break;
		case Code::NonUSBackslash:
			text = "NonUSBackslash";
			break;
		case Code::Application:
			text = "Application";
			break;
		case Code::Power:
			text = "Power";
			break;
		case Code::KpEquals:
			text = "KpEquals";
			break;
		case Code::F13:
			text = "F13";
			break;
		case Code::F14:
			text = "F14";
			break;
		case Code::F15:
			text = "F15";
			break;
		case Code::F16:
			text = "F16";
			break;
		case Code::F17:
			text = "F17";
			break;
		case Code::F18:
			text = "F18";
			break;
		case Code::F19:
			text = "F19";
			break;
		case Code::F20:
			text = "F20";
			break;
		case Code::F21:
			text = "F21";
			break;
		case Code::F22:
			text = "F22";
			break;
		case Code::F23:
			text = "F23";
			break;
		case Code::F24:
			text = "F24";
			break;
		case Code::Execute:
			text = "Execute";
			break;
		case Code::Help:
			text = "Help";
			break;
		case Code::Menu:
			text = "Menu";
			break;
		case Code::Select:
			text = "Select";
			break;
		case Code::Stop:
			text = "Stop";
			break;
		case Code::Again:
			text = "Again";
			break;
		case Code::Undo:
			text = "Undo";
			break;
		case Code::Cut:
			text = "Cut";
			break;
		case Code::Copy:
			text = "Copy";
			break;
		case Code::Paste:
			text = "Paste";
			break;
		case Code::Find:
			text = "Find";
			break;
		case Code::Mute:
			text = "Mute";
			break;
		case Code::VolumeUp:
			text = "VolumeUp";
			break;
		case Code::VolumeDown:
			text = "VolumeDown";
			break;
		case Code::KpComma:
			text = "KpComma";
			break;
		case Code::KpEqualsAS400:
			text = "KpEqualsAS400";
			break;
		case Code::International1:
			text = "International1";
			break;
		case Code::International2:
			text = "International2";
			break;
		case Code::International3:
			text = "International3";
			break;
		case Code::International4:
			text = "International4";
			break;
		case Code::International5:
			text = "International5";
			break;
		case Code::International6:
			text = "International6";
			break;
		case Code::International7:
			text = "International7";
			break;
		case Code::International8:
			text = "International8";
			break;
		case Code::International9:
			text = "International9";
			break;
		case Code::Lang1:
			text = "Lang1";
			break;
		case Code::Lang2:
			text = "Lang2";
			break;
		case Code::Lang3:
			text = "Lang3";
			break;
		case Code::Lang4:
			text = "Lang4";
			break;
		case Code::Lang5:
			text = "Lang5";
			break;
		case Code::Lang6:
			text = "Lang6";
			break;
		case Code::Lang7:
			text = "Lang7";
			break;
		case Code::Lang8:
			text = "Lang8";
			break;
		case Code::Lang9:
			text = "Lang9";
			break;
		case Code::Alterase:
			text = "Alterase";
			break;
		case Code::Sysreq:
			text = "Sysreq";
			break;
		case Code::Cancel:
			text = "Cancel";
			break;
		case Code::Clear:
			text = "Clear";
			break;
		case Code::Prior:
			text = "Prior";
			break;
		case Code::RETURN2:
			text = "RETURN2";
			break;
		case Code::Separator:
			text = "Separator";
			break;
		case Code::Out:
			text = "Out";
			break;
		case Code::Oper:
			text = "Oper";
			break;
		case Code::Clearagain:
			text = "Clearagain";
			break;
		case Code::Crsel:
			text = "Crsel";
			break;
		case Code::Exsel:
			text = "Exsel";
			break;
		case Code::Kp00:
			text = "Kp00";
			break;
		case Code::Kp000:
			text = "Kp000";
			break;
		case Code::ThousandsSeparator:
			text = "ThousandsSeparator";
			break;
		case Code::DecimalSeparator:
			text = "DecimalSeparator";
			break;
		case Code::CurrencyUnit:
			text = "CurrencyUnit";
			break;
		case Code::CurrencySubUnit:
			text = "CurrencySubUnit";
			break;
		case Code::KpLeftParen:
			text = "KpLeftParen";
			break;
		case Code::KpRightParen:
			text = "KpRightParen";
			break;
		case Code::KpLeftBrace:
			text = "KpLeftBrace";
			break;
		case Code::KpRightBrace:
			text = "KpRightBrace";
			break;
		case Code::KpTab:
			text = "KpTab";
			break;
		case Code::KpBackspace:
			text = "KpBackspace";
			break;
		case Code::KpA:
			text = "KpA";
			break;
		case Code::KpB:
			text = "KpB";
			break;
		case Code::KpC:
			text = "KpC";
			break;
		case Code::KpD:
			text = "KpD";
			break;
		case Code::KpE:
			text = "KpE";
			break;
		case Code::KpF:
			text = "KpF";
			break;
		case Code::KpXor:
			text = "KpXor";
			break;
		case Code::KpPower:
			text = "KpPower";
			break;
		case Code::KpPercent:
			text = "KpPercent";
			break;
		case Code::KpLess:
			text = "KpLess";
			break;
		case Code::KpGreater:
			text = "KpGreater";
			break;
		case Code::KpAmpersand:
			text = "KpAmpersand";
			break;
		case Code::KpDblampersand:
			text = "KpDblampersand";
			break;
		case Code::KpVerticalbar:
			text = "KpVerticalbar";
			break;
		case Code::KpDblverticalbar:
			text = "KpDblverticalbar";
			break;
		case Code::KpColon:
			text = "KpColon";
			break;
		case Code::KpHash:
			text = "KpHash";
			break;
		case Code::KpSpace:
			text = "KpSpace";
			break;
		case Code::KpAt:
			text = "KpAt";
			break;
		case Code::KpExclam:
			text = "KpExclam";
			break;
		case Code::KpMemstore:
			text = "KpMemstore";
			break;
		case Code::KpMemrecall:
			text = "KpMemrecall";
			break;
		case Code::KpMemclear:
			text = "KpMemclear";
			break;
		case Code::KpMemadd:
			text = "KpMemadd";
			break;
		case Code::KpMemsubtract:
			text = "KpMemsubtract";
			break;
		case Code::KpMemmultiply:
			text = "KpMemmultiply";
			break;
		case Code::KpMemdivide:
			text = "KpMemdivide";
			break;
		case Code::KpPlusminus:
			text = "KpPlusminus";
			break;
		case Code::KpClear:
			text = "KpClear";
			break;
		case Code::KpClearentry:
			text = "KpClearentry";
			break;
		case Code::KpBinary:
			text = "KpBinary";
			break;
		case Code::KpOctal:
			text = "KpOctal";
			break;
		case Code::KpDecimal:
			text = "KpDecimal";
			break;
		case Code::KpHexadecimal:
			text = "KpHexadecimal";
			break;
		case Code::LCtrl:
			text = "LCtrl";
			break;
		case Code::LShift:
			text = "LShift";
			break;
		case Code::LAlt:
			text = "LAlt";
			break;
		case Code::LGui:
			text = "LGui";
			break;
		case Code::RCtrl:
			text = "RCtrl";
			break;
		case Code::RShift:
			text = "RShift";
			break;
		case Code::RAlt:
			text = "RAlt";
			break;
		case Code::RGui:
			text = "RGui";
			break;
		case Code::Mode:
			text = "Mode";
			break;
		case Code::Sleep:
			text = "Sleep";
			break;
		case Code::Wake:
			text = "Wake";
			break;
		case Code::ChannelIncrement:
			text = "ChannelIncrement";
			break;
		case Code::ChannelDecrement:
			text = "ChannelDecrement";
			break;
		case Code::MediaPlay:
			text = "MediaPlay";
			break;
		case Code::MediaPause:
			text = "MediaPause";
			break;
		case Code::MediaRecord:
			text = "MediaRecord";
			break;
		case Code::MediaFastForward:
			text = "MediaFastForward";
			break;
		case Code::MediaRewind:
			text = "MediaRewind";
			break;
		case Code::MediaNextTrack:
			text = "MediaNextTrack";
			break;
		case Code::MediaPreviousTrack:
			text = "MediaPreviousTrack";
			break;
		case Code::MediaStop:
			text = "MediaStop";
			break;
		case Code::MediaEject:
			text = "MediaEject";
			break;
		case Code::MediaPlayPause:
			text = "MediaPlayPause";
			break;
		case Code::MediaSelect:
			text = "MediaSelect";
			break;
		case Code::AcNew:
			text = "AcNew";
			break;
		case Code::AcOpen:
			text = "AcOpen";
			break;
		case Code::AcClose:
			text = "AcClose";
			break;
		case Code::AcExit:
			text = "AcExit";
			break;
		case Code::AcSave:
			text = "AcSave";
			break;
		case Code::AcPrint:
			text = "AcPrint";
			break;
		case Code::AcProperties:
			text = "AcProperties";
			break;
		case Code::AcSearch:
			text = "AcSearch";
			break;
		case Code::AcHome:
			text = "AcHome";
			break;
		case Code::AcBack:
			text = "AcBack";
			break;
		case Code::AcForward:
			text = "AcForward";
			break;
		case Code::AcStop:
			text = "AcStop";
			break;
		case Code::AcRefresh:
			text = "AcRefresh";
			break;
		case Code::AcBookmarks:
			text = "AcBookmarks";
			break;
		case Code::Softleft:
			text = "Softleft";
			break;
		case Code::Softright:
			text = "Softright";
			break;
		case Code::Call:
			text = "Call";
			break;
		case Code::EndCall:
			text = "EndCall";
			break;
	}
	return text;
}

std::string Key::to_string(Code code)
{
	std::string text = "";
	switch (code) {
		case Code::Unknown:
			text = "Unknown";
			break;
		case Code::Return:
			text = "Return";
			break;
		case Code::Escape:
			text = "Escape";
			break;
		case Code::Backspace:
			text = "Backspace";
			break;
		case Code::Tab:
			text = "Tab";
			break;
		case Code::Space:
			text = "Space";
			break;
		case Code::Exclaim:
			text = "Exclaim";
			break;
		case Code::DoubleApostrophe:
			text = "DoubleApostrophe";
			break;
		case Code::Hash:
			text = "Hash";
			break;
		case Code::Dollar:
			text = "Dollar";
			break;
		case Code::Percent:
			text = "Percent";
			break;
		case Code::Ampersand:
			text = "Ampersand";
			break;
		case Code::Apostrophe:
			text = "Apostrophe";
			break;
		case Code::LeftParen:
			text = "LeftParen";
			break;
		case Code::RightParen:
			text = "RightParen";
			break;
		case Code::Asterisk:
			text = "Asterisk";
			break;
		case Code::Plus:
			text = "Plus";
			break;
		case Code::Comma:
			text = "Comma";
			break;
		case Code::Minus:
			text = "Minus";
			break;
		case Code::Period:
			text = "Period";
			break;
		case Code::Slash:
			text = "Slash";
			break;
		case Code::Number0:
			text = "Number0";
			break;
		case Code::Number1:
			text = "Number1";
			break;
		case Code::Number2:
			text = "Number2";
			break;
		case Code::Number3:
			text = "Number3";
			break;
		case Code::Number4:
			text = "Number4";
			break;
		case Code::Number5:
			text = "Number5";
			break;
		case Code::Number6:
			text = "Number6";
			break;
		case Code::Number7:
			text = "Number7";
			break;
		case Code::Number8:
			text = "Number8";
			break;
		case Code::Number9:
			text = "Number9";
			break;
		case Code::Colon:
			text = "Colon";
			break;
		case Code::Semicolon:
			text = "Semicolon";
			break;
		case Code::Less:
			text = "Less";
			break;
		case Code::Equals:
			text = "Equals";
			break;
		case Code::Greater:
			text = "Greater";
			break;
		case Code::Question:
			text = "Question";
			break;
		case Code::At:
			text = ":";
			break;
		case Code::LeftBracket:
			text = "LeftBracket";
			break;
		case Code::Backslash:
			text = "Backslash";
			break;
		case Code::RightBracket:
			text = "RightBracket";
			break;
		case Code::Caret:
			text = "Caret";
			break;
		case Code::Underscore:
			text = "Underscore";
			break;
		case Code::Grave:
			text = "Grave";
			break;
		case Code::A:
			text = "A";
			break;
		case Code::B:
			text = "B";
			break;
		case Code::C:
			text = "C";
			break;
		case Code::D:
			text = "D";
			break;
		case Code::E:
			text = "E";
			break;
		case Code::F:
			text = "F";
			break;
		case Code::G:
			text = "G";
			break;
		case Code::H:
			text = "H";
			break;
		case Code::I:
			text = "I";
			break;
		case Code::J:
			text = "J";
			break;
		case Code::K:
			text = "K";
			break;
		case Code::L:
			text = "L";
			break;
		case Code::M:
			text = "M";
			break;
		case Code::N:
			text = "N";
			break;
		case Code::O:
			text = "O";
			break;
		case Code::P:
			text = "P";
			break;
		case Code::Q:
			text = "Q";
			break;
		case Code::R:
			text = "R";
			break;
		case Code::S:
			text = "S";
			break;
		case Code::T:
			text = "T";
			break;
		case Code::U:
			text = "U";
			break;
		case Code::V:
			text = "V";
			break;
		case Code::W:
			text = "W";
			break;
		case Code::X:
			text = "X";
			break;
		case Code::Y:
			text = "Y";
			break;
		case Code::Z:
			text = "Z";
			break;
		case Code::Leftbrace:
			text = "Leftbrace";
			break;
		case Code::Pipe:
			text = "Pipe";
			break;
		case Code::Rightbrace:
			text = "Rightbrace";
			break;
		case Code::Tilde:
			text = "Tilde";
			break;
		case Code::Delete:
			text = "Delete";
			break;
		case Code::Plusminus:
			text = "Plusminus";
			break;
		case Code::Capslock:
			text = "Capslock";
			break;
		case Code::F1:
			text = ":";
			break;
		case Code::F2:
			text = ":";
			break;
		case Code::F3:
			text = ":";
			break;
		case Code::F4:
			text = ":";
			break;
		case Code::F5:
			text = ":";
			break;
		case Code::F6:
			text = ":";
			break;
		case Code::F7:
			text = ":";
			break;
		case Code::F8:
			text = ":";
			break;
		case Code::F9:
			text = ":";
			break;
		case Code::F10:
			text = "F10";
			break;
		case Code::F11:
			text = "F11";
			break;
		case Code::F12:
			text = "F12";
			break;
		case Code::Printscreen:
			text = "Printscreen";
			break;
		case Code::Scrolllock:
			text = "Scrolllock";
			break;
		case Code::Pause:
			text = "Pause";
			break;
		case Code::Insert:
			text = "Insert";
			break;
		case Code::Home:
			text = "Home";
			break;
		case Code::Pageup:
			text = "Pageup";
			break;
		case Code::End:
			text = "End";
			break;
		case Code::Pagedown:
			text = "Pagedown";
			break;
		case Code::Right:
			text = "Right";
			break;
		case Code::Left:
			text = "Left";
			break;
		case Code::Down:
			text = "Down";
			break;
		case Code::Up:
			text = ":";
			break;
		case Code::NumlockClear:
			text = "NumlockClear";
			break;
		case Code::KpDivide:
			text = "KpDivide";
			break;
		case Code::KpMultiply:
			text = "KpMultiply";
			break;
		case Code::KpMinus:
			text = "KpMinus";
			break;
		case Code::KpPlus:
			text = "KpPlus";
			break;
		case Code::KpEnter:
			text = "KpEnter";
			break;
		case Code::Kp1:
			text = "Kp1";
			break;
		case Code::Kp2:
			text = "Kp2";
			break;
		case Code::Kp3:
			text = "Kp3";
			break;
		case Code::Kp4:
			text = "Kp4";
			break;
		case Code::Kp5:
			text = "Kp5";
			break;
		case Code::Kp6:
			text = "Kp6";
			break;
		case Code::Kp7:
			text = "Kp7";
			break;
		case Code::Kp8:
			text = "Kp8";
			break;
		case Code::Kp9:
			text = "Kp9";
			break;
		case Code::Kp0:
			text = "Kp0";
			break;
		case Code::KpPeriod:
			text = "KpPeriod";
			break;
		case Code::Application:
			text = "Application";
			break;
		case Code::Power:
			text = "Power";
			break;
		case Code::KpEquals:
			text = "KpEquals";
			break;
		case Code::F13:
			text = "F13";
			break;
		case Code::F14:
			text = "F14";
			break;
		case Code::F15:
			text = "F15";
			break;
		case Code::F16:
			text = "F16";
			break;
		case Code::F17:
			text = "F17";
			break;
		case Code::F18:
			text = "F18";
			break;
		case Code::F19:
			text = "F19";
			break;
		case Code::F20:
			text = "F20";
			break;
		case Code::F21:
			text = "F21";
			break;
		case Code::F22:
			text = "F22";
			break;
		case Code::F23:
			text = "F23";
			break;
		case Code::F24:
			text = "F24";
			break;
		case Code::Execute:
			text = "Execute";
			break;
		case Code::Help:
			text = "Help";
			break;
		case Code::Menu:
			text = "Menu";
			break;
		case Code::Select:
			text = "Select";
			break;
		case Code::Stop:
			text = "Stop";
			break;
		case Code::Again:
			text = "Again";
			break;
		case Code::Undo:
			text = "Undo";
			break;
		case Code::Cut:
			text = "Cut";
			break;
		case Code::Copy:
			text = "Copy";
			break;
		case Code::Paste:
			text = "Paste";
			break;
		case Code::Find:
			text = "Find";
			break;
		case Code::Mute:
			text = "Mute";
			break;
		case Code::VolumeUp:
			text = "VolumeUp";
			break;
		case Code::VolumeDown:
			text = "VolumeDown";
			break;
		case Code::KpComma:
			text = "KpComma";
			break;
		case Code::KpEQUALSAS400:
			text = "KpEQUALSAS400";
			break;
		case Code::Alterase:
			text = "Alterase";
			break;
		case Code::Sysreq:
			text = "Sysreq";
			break;
		case Code::Cancel:
			text = "Cancel";
			break;
		case Code::Clear:
			text = "Clear";
			break;
		case Code::Prior:
			text = "Prior";
			break;
		case Code::Return2:
			text = "Return2";
			break;
		case Code::Separator:
			text = "Separator";
			break;
		case Code::Out:
			text = "Out";
			break;
		case Code::Oper:
			text = "Oper";
			break;
		case Code::Clearagain:
			text = "Clearagain";
			break;
		case Code::Crsel:
			text = "Crsel";
			break;
		case Code::Exsel:
			text = "Exsel";
			break;
		case Code::Kp00:
			text = "Kp00";
			break;
		case Code::Kp000:
			text = "Kp000";
			break;
		case Code::ThousandsSeparator:
			text = "ThousandsSeparator";
			break;
		case Code::DecimalSeparator:
			text = "DecimalSeparator";
			break;
		case Code::CurrencyUnit:
			text = "CurrencyUnit";
			break;
		case Code::CurrencySubunit:
			text = "CurrencySubunit";
			break;
		case Code::KpLeftParen:
			text = "KpLeftParen";
			break;
		case Code::KpRightParen:
			text = "KpRightParen";
			break;
		case Code::KpLeftBrace:
			text = "KpLeftBrace";
			break;
		case Code::KpRightBrace:
			text = "KpRightBrace";
			break;
		case Code::KpTab:
			text = "KpTab";
			break;
		case Code::KpBackspace:
			text = "KpBackspace";
			break;
		case Code::KpA:
			text = "KpA";
			break;
		case Code::KpB:
			text = "KpB";
			break;
		case Code::KpC:
			text = "KpC";
			break;
		case Code::KpD:
			text = "KpD";
			break;
		case Code::KpE:
			text = "KpE";
			break;
		case Code::KpF:
			text = "KpF";
			break;
		case Code::KpXor:
			text = "KpXor";
			break;
		case Code::KpPower:
			text = "KpPower";
			break;
		case Code::KpPercent:
			text = "KpPercent";
			break;
		case Code::KpLess:
			text = "KpLess";
			break;
		case Code::KpGreater:
			text = "KpGreater";
			break;
		case Code::KpAmpersand:
			text = "KpAmpersand";
			break;
		case Code::KpDblampersand:
			text = "KpDblampersand";
			break;
		case Code::KpVerticalbar:
			text = "KpVerticalbar";
			break;
		case Code::KpDblverticalbar:
			text = "KpDblverticalbar";
			break;
		case Code::KpColon:
			text = "KpColon";
			break;
		case Code::KpHash:
			text = "KpHash";
			break;
		case Code::KpSpace:
			text = "KpSpace";
			break;
		case Code::KpAt:
			text = "KpAt";
			break;
		case Code::KpExclam:
			text = "KpExclam";
			break;
		case Code::KpMemstore:
			text = "KpMemstore";
			break;
		case Code::KpMemrecall:
			text = "KpMemrecall";
			break;
		case Code::KpMemclear:
			text = "KpMemclear";
			break;
		case Code::KpMemadd:
			text = "KpMemadd";
			break;
		case Code::KpMemsubtract:
			text = "KpMemsubtract";
			break;
		case Code::KpMemmultiply:
			text = "KpMemmultiply";
			break;
		case Code::KpMemdivide:
			text = "KpMemdivide";
			break;
		case Code::KpPlusminus:
			text = "KpPlusminus";
			break;
		case Code::KpClear:
			text = "KpClear";
			break;
		case Code::KpClearentry:
			text = "KpClearentry";
			break;
		case Code::KpBinary:
			text = "KpBinary";
			break;
		case Code::KpOctal:
			text = "KpOctal";
			break;
		case Code::KpDecimal:
			text = "KpDecimal";
			break;
		case Code::KpHexadecimal:
			text = "KpHexadecimal";
			break;
		case Code::LCtrl:
			text = "LCtrl";
			break;
		case Code::LShift:
			text = "LShift";
			break;
		case Code::LAlt:
			text = "LAlt";
			break;
		case Code::LGui:
			text = "LGui";
			break;
		case Code::RCtrl:
			text = "RCtrl";
			break;
		case Code::RShift:
			text = "RShift";
			break;
		case Code::RAlt:
			text = "RAlt";
			break;
		case Code::RGui:
			text = "RGui";
			break;
		case Code::Mode:
			text = "Mode";
			break;
		case Code::Sleep:
			text = "Sleep";
			break;
		case Code::Wake:
			text = "Wake";
			break;
		case Code::ChannelIncrement:
			text = "ChannelIncrement";
			break;
		case Code::ChannelDecrement:
			text = "ChannelDecrement";
			break;
		case Code::MediaPlay:
			text = "MediaPlay";
			break;
		case Code::MediaPause:
			text = "MediaPause";
			break;
		case Code::MediaRecord:
			text = "MediaRecord";
			break;
		case Code::MediaFastForward:
			text = "MediaFastForward";
			break;
		case Code::MediaRewind:
			text = "MediaRewind";
			break;
		case Code::MediaNextTrack:
			text = "MediaNextTrack";
			break;
		case Code::MediaPreviousTrack:
			text = "MediaPreviousTrack";
			break;
		case Code::MediaStop:
			text = "MediaStop";
			break;
		case Code::MediaEject:
			text = "MediaEject";
			break;
		case Code::MediaPlayPause:
			text = "MediaPlayPause";
			break;
		case Code::MediaSelect:
			text = "MediaSelect";
			break;
		case Code::AcNew:
			text = "AcNew";
			break;
		case Code::AcOpen:
			text = "AcOpen";
			break;
		case Code::AcClose:
			text = "AcClose";
			break;
		case Code::AcExit:
			text = "AcExit";
			break;
		case Code::AcSave:
			text = "AcSave";
			break;
		case Code::AcPrint:
			text = "AcPrint";
			break;
		case Code::AcProperties:
			text = "AcProperties";
			break;
		case Code::AcSearch:
			text = "AcSearch";
			break;
		case Code::AcHome:
			text = "AcHome";
			break;
		case Code::AcBack:
			text = "AcBack";
			break;
		case Code::AcForward:
			text = "AcForward";
			break;
		case Code::AcStop:
			text = "AcStop";
			break;
		case Code::AcRefresh:
			text = "AcRefresh";
			break;
		case Code::AcBookmarks:
			text = "AcBookmarks";
			break;
		case Code::Softleft:
			text = "Softleft";
			break;
		case Code::Softright:
			text = "Softright";
			break;
		case Code::Call:
			text = "Call";
			break;
		case Code::Endcall:
			text = "Endcall";
			break;
		case Code::LeftTab:
			text = "LeftTab";
			break;
		case Code::Level5Shift:
			text = "Level5Shift";
			break;
		case Code::MultiKeyCompose:
			text = "MultiKeyCompose";
			break;
		case Code::LMeta:
			text = "LMeta";
			break;
		case Code::RMeta:
			text = "RMeta";
			break;
		case Code::LHyper:
			text = "LHyper";
			break;
		case Code::RHyper:
			text = "RHyper";
			break;
	}
	return text;
}
