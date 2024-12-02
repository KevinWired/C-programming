.PHONY: sorter clean

# Compilación.
sorter:
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c main.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 -no-pie array_helpers.o sort.o sort_helpers.o main.o -o sorter

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f main.o
	rm -f array_helpers.o
	rm -f sort.o
	rm -f sorter


