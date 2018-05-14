# Makefile - DU2
# Petr Zubalik - xzubal04@stud.fit.vutbr.cz

CC=gcc
CFLAGS=-std=c99 -pedantic -fPIC -Wall -Wextra -g
CPPFLAGS=-std=c++11 -pedantic -Wall 

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

all: tail tail2 wordcount wordcount-dynamic

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@
tail2: tail2.o
	g++ $(CPPFLAGS) $^ -o $@

wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -o wordcount -static wordcount.o io.o -L. -lhtab
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o io.o -L. -lhtab 

libhtab.a: htab_init.o htab_clear.o hfunction.o htab_lookup_add.o htab_find.o htab_remove.o func.o htab_foreach.o htab_free.o htab_size.o htab_bucket_count.o htab_move.o
	ar rcs libhtab.a $^

libhtab.so: htab_init.o htab_clear.o hfunction.o htab_lookup_add.o htab_find.o htab_remove.o func.o htab_foreach.o htab_free.o htab_size.o htab_bucket_count.o htab_move.o
	$(CC) $(CFLAGS) -shared -o libhtab.so $^

tail2.o: tail2.cc
tail.o: tail.c 

htab_init.o: htab_init.c htab.h 
htab_clear.o: htab_clear.c htab.h
hfunction.o: hfunction.c htab.h
htab_lookup_add.o: htab_lookup_add.c hfunction.c htab.h 
htab_find.o: htab_find.c htab.h 
htab_remove.o: htab_remove.c htab.h
func.o: func.c htab.h
htab_foreach.o: htab_foreach.c htab.h
htab_free.o: htab_free.c htab.h
htab_size.o: htab_size.c htab.h
htab_bucket_count.o: htab_bucket_count.c htab.h
htab_move.o: htab_move.c htab.h

wordcount.o: wordcount.c htab.h
io.o: io.c io.h

run: 
	./wordcount
	LD_LIBRARY_PATH="." ./wordcount-dynamic

zip: 
	zip xzubal04.zip *.c *.cc *.h Makefile

clean:
	rm -f *.o tail tail2 wordcount wordcount-dynamic 

