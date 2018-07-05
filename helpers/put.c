#include "put.h"
void put_char(char c){
	printf("%c", c);
}

void put_int(int i){
	printf("%d", i);
}

void put_string(const char* s){
	printf("%s", s);
}

void put_error_code_with_message(int code, const char* message){
	fflush(stdout);
	fprintf(stderr, "Error Code: %d; Error Message: %s", 
		code, message);
}
