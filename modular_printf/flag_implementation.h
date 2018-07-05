#ifndef FLAG_IMPLEMENTATION_H
#define FLAG_IMPLEMENTATION_H
#include <stdarg.h>
typedef struct {
	char flag_marker;
	const char* (*vexecute)(const char* format_string, const char* itr, va_list args);
} FlagImplementation;
#endif
