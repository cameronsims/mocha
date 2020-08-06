/* debug.h 
 *
 */
#pragma once
#define MOCHA_DEBUG true
#include "mocha.h"
#include <stdio.h>
#include <malloc.h>
void* operator new(size_t s) {
	printf("[mocha]: New Allocation of %d bytes.\n", s);
	return malloc(s);
}
void operator delete(void* b) {
	printf("[mocha]: Deleted Object Allocation\n");
	free(b);
}
namespace mocha {}
