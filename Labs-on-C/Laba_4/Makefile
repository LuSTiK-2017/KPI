CC = gcc
CFLAGS = -c -Wall

all: Laba_4

Laba_4: main.o welcome.o validation.o pointer.o recursion.o
	$(CC) main.o welcome.o validation.o pointer.o recursion.o -o Laba_4 -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

welcome.o: welcome.c
	$(CC) $(CFLAGS) welcome.c

pointer.o: pointer.c
	$(CC) $(CFLAGS) pointer.c

recursion.o: recursion.c
	$(CC) $(CFLAGS) recursion.c

validation.o: validation.c
	$(CC) $(CFLAGS) validation.c


clean:
	rm -rf *.o Laba4
