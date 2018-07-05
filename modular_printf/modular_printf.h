#ifndef MODULAR_PRINTF_H
#define MODULAR_PRINTF_H
#include "flag_implementation.h"
#include "../helpers/put.h"
#include <stdarg.h>
extern int modular_printf(FlagImplementation flag_implementations[], size_t implementations, const char *format, ...);
extern int vmodular_printf(FlagImplementation flag_implementations[], size_t implementations, const char *format,  va_list args);
#endif
