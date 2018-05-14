/**
* Petr Zubalik - xzubal04, 1BIT
* eratostenes.c
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdio.h>
#include <math.h>
#include "bit_array.h"

void eratosthenes(bit_array_t numbers)
{
	unsigned long size = numbers[0];
	ba_set_bit(numbers, 0, 1);
	ba_set_bit(numbers, 1, 1);
	int i = 0;

	for (i = 2; i < sqrt(size); i++)
	{
		if (ba_get_bit(numbers, i) == 0)
		{
			for (int j = 2; j*i <= size; j++)
			{
				ba_set_bit(numbers,j*i, 1);
			}
		}
	}
	
	return ;
}

