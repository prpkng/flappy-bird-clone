#pragma once

#include "Log.hpp"

#ifndef NDEBUG
#define DEV_ASSERT(x, ...) if (!(x)) { LOG_FATAL("Assertion Failed! "##__VA_ARGS__); abort(); } 
#else
#define DEV_ASSERT(x)
#endif