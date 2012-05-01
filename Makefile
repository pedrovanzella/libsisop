CC = clang
CFLAGS = -Wall
LIBPATH = lib

all: $(LIBPATH)/libsisop.a tests

$(LIBPATH)/libsisop.a: bin/libsisop.o bin/lists.o
	mkdir -p lib
	ar crs $(LIBPATH)/libsisop.a bin/libsisop.o bin/lists.o

bin/lists.o: src/lists.c include/lists.h include/error.h
	$(CC) $(CFLAGS) -c src/lists.c
	mkdir -p bin
	mv lists.o bin/lists.o

bin/libsisop.o: src/libsisop.c include/unucleo.h bin/lists.o include/lists.h
	$(CC) $(CFLAGS) -c src/libsisop.c
	mkdir -p bin
	mv libsisop.o bin/libsisop.o

tests: exemplo1

exemplo1: testes/exemplo1.c
	$(CC) -o bin/exemplo1 testes/exemplo1.c $(CFLAGS) -L$(LIBPATH) -lsisop

clean:
	rm -rf lib
	rm -rf bin
