#pragma once

#ifdef _WIN32
#include <intrin.h>
#else
#include <x86initrin.h>
#endif // _WIN32

#define START_TICK \
		{ uint64_t _tick = __rdtsc();

#define END_TICK \
		std::cout << (__rdtsc() - _tick) << "\n"; }
