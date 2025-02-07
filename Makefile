CC = gcc
CFLAGS = -Wall -O2

OBJ = main.o bloom.o bsgsd.o

keyhunt: $(OBJ)
	$(CC) $(CFLAGS) -o keyhunt $(OBJ)

main.o: main.c bloom.h bsgsd.h
	$(CC) $(CFLAGS) -c main.c

bloom.o: bloom.c bloom.h
	$(CC) $(CFLAGS) -c bloom.c

bsgsd.o: bsgsd.c bsgsd.h
	$(CC) $(CFLAGS) -c bsgsd.c

clean:
	rm -f *.o keyhunt