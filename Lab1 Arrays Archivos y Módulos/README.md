# Laboratorio #1: Arreglos, Archivos, Módulos

Autor: Kevin Santillan

Date: 25 nov, 2024

## Algunas flags de gcc

| Flag         | Descripción                                                                                 |
|--------------|---------------------------------------------------------------------------------------------|
| -Wall        | Activa la mayoria de advertencias comunes                                                   |
| -Werror      | Trata todas las advertencias como errores y detiene la compilación si hay advertencias      |
| -Wextra      | Activa advertencias adicionales no incluidas en -Wall                                       |
| -pedantic    | Fuerza el cumplimiento estricto del estándar C especificado                                 |
| -std=c99     | Especifica el uso del estándar C99 para la compilación                                      |
| -c           | Compila solo el archivo de origen main.c sin enlazar, generando un archivo objeto (main.o)  |

## Manejo de archivos con fopen, fscanf & fclose

Al trabajar con cualquier fuente o base de datos lo primero es abrirla. En C lo haremos con la función `fopen` usamos la macro `FILE` definida en `<stdio.h>` para declarar un puntero a un archivo.<br>
La sintaxis de la función es: 

```c
    FILE *file;
    file = fopen(const char *file_name, const char *mode_of_operation);
```

Si la ejecución tiene éxito, la función devolverá un puntero a un archivo; en caso contrario, devolverá NULL.
En cuanto al modo hay varios (`r`, `r+`, `w`, `w+`, `a`, `a+`). Nos concentraremos en el modo lectura `r` en donde es necesario que exista el archivo. Ahora bien para extraer los datos lo hacemos con la función `fscanf` que usa una cadena formateada y una lista de argumentos variables para tomar la entrada del fichero. Finalmente cerramos el archivo con `fclose`.<br>

```c
int fscanf(FILE *stream, const char *format, ...);
```
En caso de éxito, `fscanf` devuelve el número de elementos de entrada que han sido coincidentes y asignados exitosamente; esto puede ser menor que el número proporcionado o incluso cero, en caso de un fallo temprano en la coincidencia.

En C `stdin` y `stdout` son punteros a archivos que representan la entrada estándar (por defecto es el teclado) y salida estándar (por defecto la pantalla) respectivamente.

```c
    FILE *file;
    file = stdout; 
```
```c
    FILE *file;
    file = stdin; 
```

## Módulos: Archivos de cabecera
Un archivo de cabecera `.h` se incluye en un programa en C usando la directiva del preprocesador `#include` sirve para contener elementos que se incluyen en otras partes del código como prototipo de funciones y macros que son definiciones de constantes o fragmentos de código. Estas directivas de preprocesamiento se utilizan para indicar al compilador que procese estos archivos antes de la compilación.<br>

El proceso de compilación se compone de dos partes principales:<br>
- Preprocesamiento: El preprocesador de C incluye el contenido de los archivos de encabezado en los archivos de implementación donde se encuentran las directivas `#include`.<br>

- Compilación: El compilador compila los archivos de implementación resultantes `.c`, que ya incluyen el contenido de los archivos de encabezado.<br>

Entonces no es necesario pasar un archivo `.h` directamente a gcc porque su contenido deberia estar incluido en los archivos de implementación durante el preprocesamiento.<br>

## Directiva del preprocesador #ifndef
#ifndef (abreviatura de "if not defined") es una instrucción del preprocesador que se ejecuta antes de compilar el programa o librería. Comprueba si una macro no está definida por #define. En caso afirmativo, ejecuta el código; en caso contrario, se omite el código.<br>

```c
// Homemade definition for type bool.
#ifndef MYBOOL_H
#define MYBOOL_H

#define true 1
#define false 0

typedef int mybool;

#endif // MYBOOL_H
```
