.PHONY: dynamic clean run

dynamic: main.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c -o array_helpers.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c -o main.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -o dynamic array_helpers.o main.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm dynamic

# Ejecutar el programa.
run:
	./dynamic

