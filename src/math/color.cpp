#include "color.hpp"

#include "error/assertions.hpp"
#include "math/math.hpp"
#include "Log.hpp"

#include <format>
#include <cstdio>


Color::Color(const std::string& hex)
{
    DEV_ASSERT(hex.size() > 0);

    std::string str = hex.at(0) == '#' ? hex.substr(1) : hex;

    int r = 0, g = 0, b = 0, a = 255;
    switch (str.size()) {
    case 8: // Read alpha 
        sscanf_s(str.c_str(), "%02x%02x%02x%02x", &r, &g, &b, &a);
        break;
    case 6:  // Ignore alpha
        sscanf_s(str.c_str(), "%02x02x%02x", &r, &g, &b);
        break;
    case 4: // 4digit Read alpha 
        sscanf_s(str.c_str(), "%01x%01x%01x%01x", &r, &g, &b, &a);
        r += r << 4;
        g += g << 4;
        b += b << 4;
        a += a << 4;
        break;
    case 3:  // 3digit Ignore alpha
        sscanf_s(str.c_str(), "%01x%01x%01x", &r, &g, &b);
        r += r << 4;
        g += g << 4;
        b += b << 4;
        break;
    default:
        LOG_ERROR("Invalid HEX color!");
        break;
    }

    this->r = r / 255.0f;
    this->g = g / 255.0f;
    this->b = b / 255.0f;
    this->a = a / 255.0f;
}

Color::Color(unsigned int hex, ColorHexFormat format)
{
    int r = 0, g = 0, b = 0, a = 255;
    switch (format) {
    case ColorHexFormat::EightDigitAlpha:
        r = ((hex >> 24) & 0xff);
        g = ((hex >> 16) & 0xff);
        b = ((hex >> 8) & 0xff);
        a = (hex & 0xff);
        break;
    case ColorHexFormat::SixDigit:
        r = ((hex >> 16) & 0xff);
        g = ((hex >> 8) & 0xff);
        b = (hex & 0xff);
        break;
    case ColorHexFormat::FourDigitAlpha:
        r = ((hex >> 12) & 0xf); r += r << 4;
        g = ((hex >> 8) & 0xf); g += g << 4;
        b = ((hex >> 4) & 0xf); b += b << 4;
        a = (hex & 0xf); a += a << 4;
        break;
    case ColorHexFormat::ThreeDigit:
        r = ((hex >> 8) & 0xf); r += r << 4;
        g = ((hex >> 4) & 0xf); g += g << 4;
        b = (hex & 0xf); b += b << 4;
        break;
    }
    
    this->r = r / 255.0f;
    this->g = g / 255.0f;
    this->b = b / 255.0f;
    this->a = a / 255.0f;
}



std::string Color::to_string() const {
    return std::format("Color ({}, {}, {}, {})", 
        Math::roundi(r * 255),
        Math::roundi(g * 255),
        Math::roundi(b * 255),
        Math::roundi(a * 255));
}