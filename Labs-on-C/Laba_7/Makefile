CC = gcc
CFLAGS = -c -Wall

all: Laba_7

Laba_7: main.o welcome.o validation.o linked_list.o struct.o
	$(CC) main.o welcome.o validation.o linked_list.o struct.o -o Laba_7

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) linked_list.c

struct.o: struct.c
	$(CC) $(CFLAGS) struct.c 

validation.o: validation.c
	$(CC) $(CFLAGS) validation.c

welcome.o: welcome.c
	$(CC) $(CFLAGS) welcome.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o Laba_7
