/* debug.h 
 *
 */
#pragma once
#define MOCHA_DEBUG true
#include "mocha.h"
#include "vector.h"

#include <stdio.h>
#include <malloc.h>
mocha::exception::~exception() { printf("[mocha]: Exception destroyed!\n"); };
mocha::out_of_range::~out_of_range() { printf("[mocha]: Exception destroyed!\n"); };
namespace mocha {}
void* operator new(const mocha::size_t _size) {
	void* data = malloc(_size);
	printf("[mocha]: New Allocation of %d bytes. (%p)\n", _size, &data);
	return data;
}
void  operator delete(void* _data) {
	printf("[mocha]: Deleted Allocation. (%p)\n", &_data);
	free(_data);
}
void* operator new[](const mocha::size_t _size) {
	void* data = malloc(_size);
	printf("[mocha]: New Array Allocation of %d bytes. (%p)\n", _size, &data);
	return data;
}
void  operator delete[](void* _data) {
	printf("[mocha]: Deleted Array Allocation. (%p)\n", &_data);
	free(_data);
}