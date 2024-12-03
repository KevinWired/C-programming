.PHONY: phrase clean

# Compilación.
phrase:
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c scanfile.c main.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 scanfile.o main.o -o phrase

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f main.o
	rm -f scanfile.o
	rm -f phrase


