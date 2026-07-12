#pragma once


#ifndef _STR
#define _STR(x) #x
#define _MKSTR(x) _STR(x)
#endif


#ifndef NDEBUG
	#ifdef _WIN32
		#define _DEBUG_BREAK() __debugbreak()
	#else
		#define _DEBUG_BREAK() __asm__ volatile("int3")
	#endif
#else
#define _DEBUG_BREAK() 
#endif

#ifdef _WIN32
#define _FORCE_INLINE_ __forceinline
#else
#define _FORCE_INLINE_ inline
#endif

// Allow bypassing [[nodiscard]]
#ifndef _ALLOW_DISCARD_
#define _ALLOW_DISCARD_ (void)
#endif

#undef SIGN
#undef MIN
#undef MAX
#undef CLAMP


template <typename T>
constexpr const T SIGN(const T val) {
	return val > 0.0 ? + 1.0f : (val < 0 ? -1.0f : 0.0f);
}

template <typename T1, typename T2>
constexpr auto MIN(const T1 a, const T2 b) {
	return a < b ? a : b;
}

template <typename T1, typename T2>
constexpr auto MAX(const T1 a, const T2 b) {
	return a > b ? a : b;
}

template <typename T1, typename T2, typename T3>
constexpr auto CLAMP(const T1 a, const T2 min, const T3 max) {
	return a < min ? min : (a > max ? max : a);
}

