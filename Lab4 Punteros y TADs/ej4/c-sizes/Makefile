.PHONY: sizes clean run

# Compilación.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

sizes: sizes.o
	$(CC) $(CFLAGS) -o sizes sizes.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm sizes

# Ejecutar el programa.
run:
	./sizes

