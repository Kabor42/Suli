CC=gcc
CFLAGS+=-std=c99 -pedantic
LDFLAGS+=-lm -lncurses -ltinfo

PROG=rpg

all: $(PROG)

$(PROG): main.o szoba.o curs_libs.o player.o inventory.o
	$(CC) $(CFLAGS) -o $(PROG) main.o szoba.o curs_libs.o player.o inventory.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c $? $(LDFLAGS)

szoba.o: szoba.c szoba.h
	$(CC) $(CFLAGS) -c $? $(LDFLAGS)

curs_libs.o: curs_libs.c curs_libs.h
	$(CC) $(CFLAGS) -c $? $(LDFLAGS)

player.o: player.c player.h
	$(CC) $(CFLAGS) -c $? $(LDFLAGS)

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c $? $(LDFALGS)

run: $(PROG)
	./$(PROG).exe

clean:
	rm -rf *.o *.gch $(PROG)
