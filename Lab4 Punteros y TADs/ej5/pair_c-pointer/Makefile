.PHONY: pair clean run mleaks

pair: main.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c pair.c -o pair.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c -o main.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -o pair pair.o main.o

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm pair

# Ejecutar el programa.
run:
	./pair

mleaks:
	valgrind --leak-check=full ./pair

