
CFLAGS = -c -Wall -std=c11 -g -o2 -fopenmp

LDFLAGS = 

SRCS= main.c functions.c

OBJS = main.o functions.o

all: project $(SRCS)

project: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o project
functions.o:
	$(CC) $(CFLAGS) functions.c -o functions.o
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

clean:
	rm -rf $(OBJS)
