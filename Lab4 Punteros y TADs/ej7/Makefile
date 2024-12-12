CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
OBJ = list.o array_helpers.o main.o
TARGET = average

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

array_helpers.o: array_helpers.c
	$(CC) $(CFLAGS) -c array_helpers.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
