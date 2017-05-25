CC=gcc
CFLAGS=-ansi -pedantic -Wall -o2
all: gpsdateparser

gpsdateparser: main.o config.o input.o output.o date.o
	$(CC) $(CFLAGS) -o gpsdateparser main.o config.o input.o output.o date.o

main.o: main.c config.h input.h output.h date.h
	$(CC) $(CFLAGS) -o main.o -c main.c

config.o: config.c config.h
	$(CC) $(CFLAGS) -o config.o -c config.c

input.o: input.c input.h config.h
	$(CC) $(CFLAGS) -o input.o -c input.c

output.o: output.c output.h date.h config.h
	$(CC) $(CFLAGS) -o output.o -c output.c

date.o: date.c date.h config.h 
	$(CC) $(CFLAGS) -o date.o -c date.c
