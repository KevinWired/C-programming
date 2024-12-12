.PHONY: counter clean run mleaks

counter: main.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c counter.c main.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 counter.o main.o -o counter

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f *.o
	rm counter

# Ejecutar el programa.
run:
	./counter ./input/balanced.in

mleaks:
	valgrind --leak-check=full ./counter

