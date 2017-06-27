.PHONY:clean all
CC=g++
CFLAGS=-Wall -g -std=c++11
BIN=combination

all:$(BIN)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)

