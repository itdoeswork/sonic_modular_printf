#include <stdarg.h>
#include "modular_printf/modular_printf.h"
#include "modules/character_implementation.h"
#include "modules/string_implementation.h"
#include "modules/integer_implementation.h"

int doge_printf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    FlagImplementation implementations[]  =  {integer_implementation_get('d'), string_implementation_get('s'), character_implementation_get('c')};
    int ret = vmodular_printf(implementations, 3, fmt, args);
    va_end(args);
    return ret;
}	

int main(){
	int ret = 0;
	//Regular Test:
	ret = ret & doge_printf("Testing, Testing: %d %d %d, Char: %c, Hello %s!\n", 1, 2, 3, 'c', "sonic");
	//Error Test:
	//ret = ret & doge_printf("%e", "Wont Work");
	return ret;
}
