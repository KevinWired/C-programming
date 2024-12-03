.PHONY: atp clean run

# Compilación.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

atp: main.o helpers.o sort.o
	$(CC) $(CFLAGS) -o atp main.o helpers.o sort.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f main.o sort.o
	rm -f helpers.o
	rm -f atp

# Ejecutar el programa.
run:
	./atp ../input/atp-players2022.in

