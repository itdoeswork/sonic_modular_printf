#ifndef PUT_H
#define PUT_H
#include <stdio.h>
//I assumed you implemented these from first principles already,
//so I didn't waste my time, and just cheated with the output.
//But assuming that your versions work as a drop-in replacement
//for this interface, you should be fine.
extern void put_char(char);
extern void put_int(int);
extern void put_string(const char*);

//If you don't have this, you don't have to print a string for it, just return a correct error value per the spec, I just do this for clairty.
extern void put_error_code_with_message(int, const char*);
#endif
