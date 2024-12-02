.PHONY: run clean

# Compilación.
run:
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c fixstring.c main.c sort.c sort_helpers.c
	gcc -Wall -Wextra -std=c99 array_helpers.o fixstring.o main.o sort.o sort_helpers.o -o word_sorter

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o word_sorter

