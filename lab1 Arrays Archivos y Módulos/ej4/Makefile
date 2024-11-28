.PHONY: run clean

# Compilación.
run:
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o main.o -o reader

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f reader *.o

