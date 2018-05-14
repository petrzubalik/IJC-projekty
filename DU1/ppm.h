/**
* Petr Zubalik - xzubal04, 1BIT
* ppm.h
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#ifndef PPM_H
#define PPM_H

#define MAXLIMIT 1000*1000*3

struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[];
};

//function reads data from the ppm file and saves it in 'the ppm struct' 
struct ppm *ppm_read(const char *filename);

//function writes data from 'the ppm struct' to the ppm file 
int ppm_write(struct ppm *p, const char *filename);

	


#endif /* PPM_H */