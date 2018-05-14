#Makefile k IJC - DU1
#Petr Zubalik

CC=gcc
CFLAGS=-O2 -std=c99 -Wall -pedantic -g

%.o : %.c 
		$(CC) $(CFLAGS) -c $<

all: primes primes-i  steg-decode

primes.o: primes.c bit_array.h eratosthenes.h
error.o: error.c error.h 
eratosthenes.o: eratosthenes.c eratosthenes.h bit_array.h

steg-decode.o: steg-decode.c ppm.h error.h bit_array.h eratosthenes.h



primes: primes.o eratosthenes.o error.o eratosthenes.h
		$(CC) $(CFLAGS) error.o primes.o eratosthenes.o -lm -o $@

primes-i: primes.o eratosthenes.o error.o eratosthenes.h
		$(CC) -DUSE_INLINE $(CFLAGS) error.o primes.o eratosthenes.o -lm -o $@

ppm: ppm.c error.c  
		$(CC) $(CFLAGS) error.o ppm.o -lm -o $@

steg-decode: steg-decode.o ppm.o error.o eratosthenes.o 
		$(CC) $(CFLAGS) steg-decode.o ppm.o error.o eratosthenes.o  -lm -o $@

clean: 
	$(RM) primes *.o primes-i steg-decode xzubal04.zip

run: all 
	time ./primes
	time ./primes-i

zip: *.c *.h Makefile
	zip xzubal04.zip *.c *.h Makefile
