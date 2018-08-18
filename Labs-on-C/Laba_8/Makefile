CC = gcc
CFLAGS = -c -Wall

all: Laba_8

Laba_8: main.o run.o task_1.o task_2.o validation.o
	$(CC) main.o run.o task_1.o task_2.o validation.o -o Laba_8

task_1.o: task_1.c 
	$(CC) $(CFLAGS) task_1.c

task_2.o: task_2.c
	$(CC) $(CFLAGS) task_2.c

validation.o: validation.c
	$(CC) $(CFLAGS) validation.c

run.o: run.c
	$(CC) $(CFLAGS) run.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o Laba_8
