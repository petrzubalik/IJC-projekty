/**
* Petr Zubalik - xzubal04, 1BIT
* bit_array.h
* IJC - DU 1
* preklad - gcc 5.4.0 
*/

#include <stdio.h>
#include <limits.h>
#include "error.h"

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef unsigned long bit_array_t[];

#define UL_SIZE (sizeof(unsigned long)*CHAR_BIT)

#define SIZE(p) (sizeof(*p)*CHAR_BIT) 

#define BA_GET_BIT_(p, i)  ((p[((i)/(SIZE(p))+1)] & ( 1UL << (i)%(SIZE(p)))) != 0) 

#define BA_SET_BIT_(p, i, b) (b != 0) ? ((p[(((i) / SIZE(p)) + 1)] |= (1UL << (i)%(SIZE(p))))) : ((p[((i) / (SIZE(p))+1)] &= ~(1UL << (i)%(SIZE(p)))))  

#define ba_size(name) (name[0])

#define ba_create(name, size) unsigned long name[(size/(UL_SIZE)) + ((size%(UL_SIZE)) == 0 ? 0 : 1)+1] = {size, 0};

#define ba_set_bit(name, index, exp) ( ((index > ba_size(name)) || (index < 0)) ? ((error_msg("Index '%lu' is out of interval <0;%lu> \n", index, ba_size(name))), 0) \
																		   		: (BA_SET_BIT_(name, index, exp)) ) 

#define ba_get_bit(name, index) ((((index) > ba_size(name)) || (index < 0)) ? ((error_msg("Index '%lu' is out of interval <0;%lu> \n", index, ba_size(name))), 0)  \
																	   		: (BA_GET_BIT_(name, index)))

#ifdef USE_INLINE

	static inline void ba_set_bit(name, index, exp)
	{
		if (((index) > ba_size(name)) || (index < 0))
		{
			(error_msg("Index '%lu' is out of interval <0;%lu> \n", index, ba_size(name)));

		} else {

			BA_SET_BIT(name, index, exp);
		}
	}

	static inline int ba_get_bit(name, index)
	{
		if (((index) > ba_size(name)) || (index < 0))
		{
			(error_msg("Index '%lu' is out of interval <0;%lu> \n", index, ba_size(name)));
		} else {

			return (BA_GET_BIT(name, index));
		}
	}

	static inline void ba_size(name)
	{
		return (name[0]);
	}

#endif /* USE_INLINE */
	

#endif /* BIT_ARRAY_H */