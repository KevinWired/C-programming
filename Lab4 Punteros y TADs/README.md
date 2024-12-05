# Laboratorio #4: Punteros
* Autor: Kevin Santillan
* Date: 4 dic, 2024
* Last Update: 5 dic, 2024


## Punteros

Una estructura de datos dínamica puede crecer o decrecer en tiempo de ejecución.
Un arreglo en C es una estructura estática, porque al declararlo se debe indicar cuantos elementos va a tener y ese número de elementos no cambia mientras exista el arreglo. En contraste las estructuras dinámicas no tienen esa limitación.<br>
Dentro de la memoria de la computadora cada dato almacenado ocupa una o más celdas contiguas de memoria. El número de celdas de memoria requeridas para almacenar un dato depende de su tipo.<br>

**Punteros**<br>
Un puntero es variable cuyo contenido no es un dato, sino la dirección de memoria donde está almacenado un dato. Tienen diferentes propositos como pueden ser:<br>
* Cadenas de caracteres.<br>
* Asignación de memoria dinámica.<br>
* Pasar argumentos de funciones por referencia.
* Construir estructuras de datos especiales o complejas.
* Apuntar a funciones.<br>
* Devolución de punteros.<br>
* Punteros a punteros.<br>

Nota: Los operadores monarios tienen mayor precedencia que el de los operadores aritméticos y la asociatividad de los operadores monarios es de derecha a izquierda.<br>

## El operador sizeof

El operador monario `sizeof()` devuelve la cantidad de bytes de un tipo determinado. Más precisamente al hacer algo como
sizeof(int) lo que se retorna es en realidad aldo del tipo size_t, que es generalmente un entero sin signo de 64 bits (por eso usamos `%lu` o `%llu` a la hora de imprimir su valor).

**Arreglos y sizeof**<br>
Supongamos que ahora tenemos declarado un arreglo de la siguiente forma:<br>

```c
int main(int argc, char *arv[])
{
    char char_J = 'J';
    int array[10];
    printf("%lu Byte.\n", sizeof(char_J)); // Size 1 byte.
    printf("%lu Bytes.\n", sizeof(int)); // Size 4 bytes.
    printf("Number of elements in the array: %lu.\n", sizeof(array)/sizeof(int));
    return 0;
}

// Output:
// 1 Byte.
// 4 Bytes.
// Number of elements in the array: 10.
```
Cuando el tamaño del array se evalua, se hace como un todo, osea que `sizeof(array)` nos da el total de bytes que ocupa. Ahora el array es de tipo `int`, entonces podemos hacer la cuenta `sizeof(array)/sizeof(int)` y así obtener la cantidad total de elementos del array, diez.<br>

## Desreferencia (o indirección)

El operador de desreferencia `*` toma una dirección de memoria, se posiciona en esa dirección y mira que valor se está almacenando. Este operador tiene su utilidad si se quiere visualizar algún dato o incluso modificarlo:

```c
#include <stdio.h>

int main(int argc, char *arv[])
{
    int x = 10;
    int* ptr_to_x = &x;
    printf("x = %d\n", x);
    *ptr_to_x = x+1;
    
    printf("x = %d\n", x);
    int array[3] = {2,9,0};
    for (unsigned int i=0; i<3; i++) {
        printf("Index: %u content: %d\n", i, *(array+i));
    }
    
    return 0;
}

// Output:
// x = 10
// x = 11
// Index: 0 content: 2
// Index: 1 content: 9
// Index: 2 content: 0
```

Nota: No confundir la declaración de una variable tipo puntero con el operador de desreferenciacón.<br>

## Punteros y arreglos unidimencionales

Los punteros y los arrays tienen una relación muy estrecha, ya que el nombre del arreglo es en realidad un puntero al primer elemento de ese arreglo. Entonces la dirección del primer elemento puede ser expresada como `&array[0]` o `array` de forma similar con `&array[i]` o `(array+i)` expresamos la dirección del i-ésimo elemento.<br>
Por otra parte con `*(array+i)` y `array[i]` representamos el contenido almacenado en esa dirección.<br>

Nota: Se prefiere `*(x+i)` antes que`x[i]` cuando la velocidad de ejecución es un factor determinante.<br>


**Resumen**<br>
Podemos tener variables "normales" y utilizar el operador `&` para conocer su dirección de memoria. O podemos tener variables tipo puntero, que ya son en sí mismas direcciones de memoria, y utilizar el operador `*` para acceder al dato que contienen.<br>
* El operador dirección `&` sólo puede actuar sobre variables que no sean punteros.<br>
* El operador indirección `*` sólo puede actuar sobre variables que sean punteros.<br>

## Manejo de memoria asignada diámicamente

En la memoria del sistema la fragmentación se produce cuando los procesos asignados han ocupado posiciones no contiguas de memoria dejando demasiados bloques libres de pequeño tamaño, en los que no "caben" nuevos procesos.<br>
**Fragmentación externa**<br>
Ocurre cuando hay suficiente memoria libre, pero está distribuida en pequeños bloques no contiguos, lo que impide asignar memoria a procesos que requieren un bloque grande y continuo.<br>
**Fragmentación interna**<br>
Sucede cuando se asigna más memoria de la necesaria debido al tamaño fijo de los bloques de memoria, lo que deja pequeñas porciones inutilizadas dentro de esos bloques.<br>

Es por esta razón que luego de haber reservado memoria con alguna fución como `malloc` o del estilo se debe verificar que el puntero no sea `NULL`, por ejemplo:<br>

```c
#include <stdio.h>
#include <stdlib.h>

int main(int arc, char *arv[])
{
	int* p = malloc(sizeof(int));
	if (p == NULL) { // Posible fragmentación de memoria.
		return 1;
	}
	*p = 7;
	printf("Content of p = %d\nAddress of p = %p\n",*p, &p);
	free(p);

	return 0;
}

// Output:
// Content of p = 7
// Address of p = 0x7ffe929dc070
```
## Devolución de punteros

Una función retorna un puntero cuando el nombre de la función es precedida por un asterisco. Por ejemplo:<br>
```c
#include <stdio.h>

double* funcion() {
    static double valor = 9.0; // Usamos una variable estática para que permanezca después de que la función termine.
    double* f_ptr = &valor;
    return f_ptr;
}

int main()
{
    double* ptr = funcion();
    printf("Retornando el puntero: %p\n", (void*)ptr); // %p para imprimir punteros.
    printf("Valor apuntado: %lf\n", *ptr); // %lf para imprimir double.
    return 0;
}
// Output:
// Retornando el puntero: 0x5d6e16fef010
// Valor apuntado: 9.000000
```
