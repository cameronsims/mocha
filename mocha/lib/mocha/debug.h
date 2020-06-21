/* debug.h */
#pragma once
#include "mocha.h"
#include "console.h"
#include <malloc.h>

#define mocha_debug true

#ifdef mocha_debug
void* operator new(size_t s) {
	mocha::clog << "[mocha]: New Allocation of " << (char*)s << " bytes.\n";
	malloc(s);
}
void operator delete(void* b) {
	mocha::clog << "[mocha]: Deleted Object Allocation\n";
	free(b);
}
#endif