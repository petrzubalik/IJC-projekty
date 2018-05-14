/**
* Petr Zubalik - xzubal04, 1BIT
* error.h
* IJC -DU 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"
#include "bit_array.h"

struct ppm * ppm_read(const char *filename)
{
	FILE *f;
	// opening test
	if ((f = fopen(filename, "rb")) == NULL)
	{
		warning_msg("Soubor '%s' se nepodarilo otevrtit\n", filename);
		return NULL;
	}

	char format[3];			// array made for 2 chars which represent a format of the file
	unsigned xsize;
	unsigned ysize;
	int depth;

	// reading of the head of the file 'filename'
	if ((fscanf(f, "%s %u %u %d", format, &xsize, &ysize, &depth)) != 4)
	{	
		warning_msg("Hlavicku souboru '%s' se nepodarilo nacist\n", filename);
		return NULL;
	}

	int limit = xsize*ysize*3;	//temporary variable for testing limits
	// limit test
	if (limit > MAXLIMIT)
	{
		warning_msg("Velikost obrazku '%s' nevyhovuje limitum\n", filename);
		return NULL;
	}
	// format test
	if ((strcmp("P6", format)) != 0)
	{
		warning_msg("Obrazek '%s' je spatneho formatu\n", filename);
		return NULL;
	}
	// color test
	if (depth > 255 || depth < 0)
	{
		warning_msg("Rozsah barev je ve spatnem rozmezi\n");
		return NULL;
	}

	char test;		//tmp variable for testing fscanf

	if((fscanf(f,"%c", &test)) != 1)
	{
		warning_msg("Pri cteni hlavicky se vyskytla chyba\n");
		return NULL;
	}
	//definition of new struct
	struct ppm *tmp; 
	//allocation of needed memory
	if ((tmp = malloc(sizeof(struct ppm) + limit)) == NULL)
	{
		warning_msg("Alokace potrebneho prostoru v pameti se nepodarila\n");
		fclose(f);
		return NULL;
	}

	tmp->xsize = xsize;
	tmp->ysize = ysize;
	//reading data from the file
	if ((fread(tmp->data, sizeof(char), limit, f)) != limit)
	{
		warning_msg("Pri cteni binarnich dat ze souboru '%s' se vyskytla chyba\n", filename);
		fclose(f);
		free(tmp);
		return NULL;
	}
	//file should be ended with EOF 
	if (fgetc(f) != EOF)
	{
		warning_msg("Soubor '%s' by mel byt zakoncen znakem EOF", filename);
		fclose(f);
		free(tmp);
		return NULL;
	}

	fclose(f);
	return tmp;
}

int ppm_write(struct ppm *p, const char *filename)
{
	FILE *f;
	// opening test
	if ((f = fopen(filename,"wb")) == NULL)
	{
		warning_msg("Soubor '%s' se nepodarilo otevrit pro zapsani dat\n", filename);
		return -1;
	}

	unsigned xsize = p->xsize;
	unsigned ysize = p->ysize;
	// print the head of file
	if (fprintf(f, "P6 \n%u %u \n255\n", xsize, ysize) < 4)
	{	
		fclose(f);
		warning_msg("Do souboru '%s' se nepodarilo zapsat hlavicku\n", filename);
		return -1;
	}

	int limit = (p->xsize)*(p->ysize)*3;
	//print the data in the file
	if((fwrite(p->data, sizeof(char), limit, f)) != limit)
	{
		fclose(f);
		warning_msg("Do souboru '%s' se nepodarilo zapsat data\n", filename);
		return -1;
	}

	fclose(f);
	return 0;

}

/*int main(int argc, char **argv) 
{
	
	struct ppm *tmp = ppm_read(argv[1]);

	ppm_write(tmp, argv[2]);

	return 0;
}*/