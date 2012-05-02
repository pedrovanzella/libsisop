CC = clang
CFLAGS = -Wall
LIBPATH = lib

all: $(LIBPATH)/libsisop.a tests

$(LIBPATH)/libsisop.a: bin/libsisop.o bin/lists.o bin/pcb.o bin/dispatcher.o
	mkdir -p lib
	ar crs $(LIBPATH)/libsisop.a bin/libsisop.o bin/lists.o bin/pcb.o bin/dispatcher.o

bin/dispatcher.o: src/dispatcher.c include/dispatcher.h bin/pcb.o bin/lists.o include/lists.h include/pcb.h
	$(CC) $(CFLAGS) -c src/dispatcher.c
	mkdir -p bin
	mv dispatcher.o bin/dispatcher.o

bin/pcb.o: src/pcb.c include/pcb.h include/error.h
	$(CC) $(CFLAGS) -c src/pcb.c
	mkdir -p bin
	mv pcb.o bin/pcb.o

bin/lists.o: src/lists.c bin/pcb.o include/lists.h include/error.h
	$(CC) $(CFLAGS) -c src/lists.c
	mkdir -p bin
	mv lists.o bin/lists.o

bin/libsisop.o: src/libsisop.c include/unucleo.h bin/lists.o bin/pcb.o bin/dispatcher.o include/dispatcher.h include/pcb.h include/lists.h
	$(CC) $(CFLAGS) -c src/libsisop.c
	mkdir -p bin
	mv libsisop.o bin/libsisop.o

tests: bin/exemplo1 bin/exemplo2 bin/par_ou_impar

bin/exemplo1: testes/exemplo1.c
	$(CC) -o bin/exemplo1 testes/exemplo1.c $(CFLAGS) -L$(LIBPATH) -lsisop

bin/exemplo2: testes/exemplo2.c
	$(CC) -o bin/exemplo2 testes/exemplo2.c $(CFLAGS) -L$(LIBPATH) -lsisop

bin/par_ou_impar: testes/par_ou_impar.c
	$(CC) -o bin/par_ou_impar testes/par_ou_impar.c $(CFLAGS) -L$(LIBPATH) -lsisop

clean:
	rm -rf lib
	rm -rf bin
