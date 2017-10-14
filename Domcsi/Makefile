CC=gcc
CFLAGS += -std=c99 -Wall -Werror -pedantic -O2
LDFLAGS +=-lm -lncurses

HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
TARGETS := $(SOURCES:.c=)

all: $(TARGETS)

% : %.c $(HEADERS)
	$(CC) $(CFLAGS) "$<" -o "$@" $(LDFLAGS)

clean:
	rm -f $(TARGETS)
