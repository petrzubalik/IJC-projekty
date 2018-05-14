/**
* Petr Zubalik - xzubal04, 1BIT
* error.h
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdarg.h>

// definition of ERROR_H
#ifndef ERROR_H
#define ERROR_H

//function prints warning message, it does not end the program
void warning_msg(const char *fmt, ...);

//function prints error message and ends the program
void error_msg(const char *fmt, ...);

#endif
