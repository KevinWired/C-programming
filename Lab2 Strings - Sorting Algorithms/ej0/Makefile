.PHONY: run clean

# Compilación.
run:
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c fixstring.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 fixstring.o main.o -o fixstring

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f fixstring *.o

