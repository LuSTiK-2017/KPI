CC = gcc
CFLAGS = -c -Wall

all: Laba_6

Laba_6: main.o welcome.o validation.o dinamic.o
	$(CC) main.o welcome.o validation.o dinamic.o -o Laba_6

main.o: main.c
	$(CC) $(CFLAGS) main.c

welcome.o: welcome.c
	$(CC) $(CFLAGS) welcome.c

dinamic.o: dinamic.c
	$(CC) $(CFLAGS) dinamic.c

validation.o: validation.c
	$(CC) $(CFLAGS) validation.c

clean:
	rm -rf *.o Laba_6
