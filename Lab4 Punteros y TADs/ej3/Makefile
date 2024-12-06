.PHONY: mysort clean run

# Compilación.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

mysort: main.o helpers.o sort.o
	$(CC) $(CFLAGS) -o mysort main.o helpers.o sort.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm -f mysort

# Ejecutar el programa.
run:
	./mysort ./input/atp-players2022.in

