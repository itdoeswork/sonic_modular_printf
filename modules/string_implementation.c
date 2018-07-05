#include "string_implementation.h"
const char* _string_vexecute(const char *format, const char *itr, va_list args){
	const char* s = va_arg(args, const char*);
	put_string(s);
	return itr;
}
FlagImplementation string_implementation_get(char marker){
	FlagImplementation ret =  {marker, &_string_vexecute};
	return ret;
}
