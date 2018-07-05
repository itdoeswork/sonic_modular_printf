#include "character_implementation.h"
const char* _char_vexecute(const char *format, const char *itr, va_list args){
	char c = va_arg(args, int);
	put_char(c);  
	return itr;
}
FlagImplementation character_implementation_get(char marker){
	FlagImplementation ret = {marker, &_char_vexecute};
	return ret;
}
