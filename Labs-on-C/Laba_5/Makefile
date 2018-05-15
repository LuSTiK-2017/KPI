CC = gcc
CFLAGS = -c -Wall

all: Laba_5

Laba_5: main.o welcome.o validation.o struct.o
	$(CC) main.o welcome.o validation.o struct.o -o Laba_5

main.o: main.c
	$(CC) $(CFLAGS) main.c

welcome.o: welcome.c
	$(CC) $(CFLAGS) welcome.c

struct.o: struct.c
	$(CC) $(CFLAGS) struct.c

validation.o: validation.c
	$(CC) $(CFLAGS) validation.c

clean:
	rm -rf *.o Laba_5
