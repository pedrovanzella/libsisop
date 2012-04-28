CC = gcc
CFLAGS = -Wall
LIBPATH = lib

all: $(LIBPATH)/libsisop.a tests

$(LIBPATH)/libsisop.a: bin/libsisop.o
	mkdir -p lib
	ar crs $(LIBPATH)/libsisop.a bin/libsisop.o

bin/libsisop.o:
	$(CC) $(CFLAGS) -c src/libsisop.c
	mkdir -p bin;
	mv libsisop.o bin/libsisop.o

tests: exemplo1

exemplo1:
	$(CC) -o bin/exemplo1 testes/exemplo1.c $(CFLAGS) -L$(LIBPATH) -lsisop

clean:
	rm -rf lib
	rm -rf bin
