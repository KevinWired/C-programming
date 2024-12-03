.PHONY: weather clean run

# Compilación.
weather: array_helpers.o main.o weather.o weather_utils.o
	gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o main.o weather.o weather_utils.o -o weather

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f main.o weather.o
	rm -f weather_utils.o array_helpers.o
	rm -f weather

# Ejecutar el programa.
run:
	./weather ../input/weather_cordoba.in

