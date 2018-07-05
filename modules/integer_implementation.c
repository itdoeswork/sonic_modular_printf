#include "integer_implementation.h"
const char* _integer_vexecute(const char *format, const char *itr, va_list args){
	int i = va_arg(args, int);
	put_int(i);  
	return itr;
}

FlagImplementation integer_implementation_get(char marker){
	FlagImplementation ret =  {marker, &_integer_vexecute};
	return ret;
}
