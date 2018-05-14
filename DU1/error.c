/**
* Petr Zubalik - xzubal04, 1BIT
* error.c
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdarg.h>
#include <stdio.h>
#include "error.h"
#include <stdlib.h>

void warning_msg(const char *fmt, ...)
{
	va_list params;
	va_start(params, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, params);
	va_end(params);
}


void error_msg(const char *fmt, ...)
{
	va_list params;
	va_start(params, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, params);
	va_end(params);
	exit(1);
}

