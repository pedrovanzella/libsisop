CC = gcc
CFLAGS = -Wall

lib/libsisop.a: bin/libsisop.o
	ar crs lib/libsisop.a bin/libsisop.o

bin/libsisop.o:
	$(CC) $(CFLAGS) -c src/libsisop.c
	mv libsisop.o bin/libsisop.o

clean:
	rm -rf lib/*
	rm -rf bin/*
