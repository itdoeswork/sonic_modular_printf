#include "modular_printf.h"
int modular_printf(FlagImplementation flag_implementations[], size_t num_implementations, const char *format, ...){
    va_list args;
    va_start(args, format);
    int ret = vmodular_printf(flag_implementations, num_implementations, format, args);
    va_end(args);
    return ret;
}

int vmodular_printf(FlagImplementation flag_implementations[], size_t num_implementations, const char *format,  va_list args){
    int escape = 0;
    int flag = 0;
    const char* fmt = format;
    while(*fmt != '\0'){        
        if(escape){
	   //If we're in escape mode, print the next charater no matter what, then turn escape mode off.
	   put_char(*fmt);
	   escape = 0;
	}else if(flag){
	   int i = 0;
	   int found = 0;
	   while(i < num_implementations){
		if(*fmt == flag_implementations[i].flag_marker){
			//This function by specification advances the pointer 
			//to the end of the flag in mult-character examples.
			fmt = flag_implementations[i].vexecute(format, fmt, args); 	
			found = 1;
			break;
		}
		i++;
	   }
	   if(!found){
		//put_error_code_with_message(1, "Unrecognized flag!");
		return 1;
	   }
	   //Exit flag mode after flag is dealt with..
	   flag = 0;
	}else{
           if(*fmt == '\\'){
             escape = 1;
	   }else if(*fmt == '%'){
             flag = 1;
	   }else{
		put_char(*fmt);
	   }
	}
        fmt++;
    }
    return 0;
}
