/**
* Petr Zubalik - xzubal04, 1BIT
* primes.c
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.h"

#define N 303000000

int main()
{	
	unsigned long tmp_arr[10];
	ba_create(pole, N);
	int counter = 0;
	eratosthenes(pole);

	for (int i = ba_size(pole); i > 0; i--)
	{
		if (ba_get_bit(pole, i) == 0)
		{
			tmp_arr[counter] = i;
			counter++;
			
			if (counter == 10)
			{
				break;
			}
		}
	}
	for (int i = 0; i < counter; i++)
	{
		printf("%lu\n", tmp_arr[i]);
	}

	return 0;
}
