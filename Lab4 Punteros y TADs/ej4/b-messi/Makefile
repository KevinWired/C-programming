.PHONY: messi clean run

# Compilación.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

messi: main.o
	$(CC) $(CFLAGS) -o messi main.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm messi

# Ejecutar el programa.
run:
	./messi

