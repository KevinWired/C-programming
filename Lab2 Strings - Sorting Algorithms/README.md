# Laboratorio #2: Cadenas & Algortimos de ordenamiento

Autor: Kevin Santillan

Date: 28 nov, 2024

Last Update: 2 dic, 2024

## Cadenas en C

En C el tipo de cadena de caracteres, (string), no existe y por ende no existe ningún operador para manipular cadenas de caracteres.<br>

Siempre que tengamos algo entre un par de comillas dobles, por ejemplo la palabra queso, ("queso"), tendremos una cadena literal, por lo que en algún lugar de la memoria estará la secuecia de caracteres `'q' 'u' 'e' 's' 'o' '\0'` donde el último carácter visible es seguido del carácter especial cuyos bits son ceros y se lo conoce como carácter nulo, se lo representa con `'\0'` y es quien marca el final de la secuencia de caracteres.<br>

No está especificado por el estándar de C, en que parte de la memoria se guardan las cadenas literales.<br>

Existen $3$ formas de declarar una variable de tipo cadena de caracteres:<br>
- 1: `char *name;`
- 2: `char name[];`
- 3: `char name[20];`<br>

Nota: Un carácter, (`char`), en C tiene un tamaño de 1 byte.

**Ejemplo 1:**

```c
char s1[] = "queso";
```
Lo que sucede con este primer ejemplo, es que se creara un arreglo de caracteres de $6$ caracteres de largo y ahora existe en el stack (pila) y sabemos que es posible modificar las cosas que están en la pila.<br>

**Ejemplo 2:**

```c
char *s2 = "hongo";
```
Exactamente donde se guarda `s2` en memoria, no está definido por el estándar de C. Pero está vez no tenemos un array, sino un puntero a un carácter, al primer carácter de `s2` pero está vez no podremos modificar `s2`. Sucede que si intentamos modificar a `s2`, estaríamos intentando modificar un lugar en la memoria el cual no podemos modificar.<br>

**Diferencias entre `s1` y `s2`:**
`s1` actua como un puntero const y o como un array de caracteres mientras que `s2` en realidad es un puntero y podemos tratarlo como tal.<br>

**Segmentation fault:**

```c
char s3[5]={'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
```
Es muy importante no olvidarse de poner el `'\0'` final ya que de lo contrario `printf()` va a recorrer a `s3[]` por fuera de su rango hasta que aparezca un `'\0'` y al acceder a memoria inválida se producirá eventualmente una violación de segmento.<br>

## Ordenación por selección (selection sort)

Es el algoritmo de ordenación más sencillo en cuanto a su idea para llevar a cabo la ordenación pero no el más rápido.<br>
`selection_sort` es adecuado para conjuntos pequeños o cuando la memoria es limitada, pero no es eficiente para arreglos grandes debido a su costo cuadrático $O(n^{2})$.<br>

**Idea del algoritmo**
* Selección: selecciona el elemento mínimo del arreglo y lo intercambia con el elemento que se encuentra en la primera posición. Ahora selecciona el menor de todos los restantes y lo intercambia con el elemento de la segunda posición y repite este proceso hasta ordenar completamente el arreglo, es decir en cada uno de estos pasos ordena un elemento hasta terminar.<br>
* Invariante: El segmento inicial $a[0,i)$ del arreglo contiene los mínimos y están ordenados.

## Ordenación por inserción (insertion_sort)

La ordenación por inserción (en inglés insertion sort), es un algoritmo sencillo que funciona insertando iterativamente cada elemento del arreglo, en el segmento inicial $a[1,i)$ notar que este segmento incial está ordenado, pero en general $a[0,i)$ no contiene los mínimos del arreglo.<br>
Es como ordenar cartas, donde se tienen dos grupos las ordenadas y las sin ordenar, entonces tomamos una carta del grupo sin ordenar y la colocamos en orden en el grupo de las cartas ordenadas:<br>

**Idea del algoritmo**
* Se asume que el primer elemento del arreglo está en el grupo ordenado, entonces comparamos con el segundo elemento del arreglo.<br>
* Comparamos el primer elemento con el segundo, si el segundo es más pequeño entonces se intercambian y el segmento inicial $a[0,i=2)$ queda ordenado.<br>
* Ahora se mira el tercer elemento del arreglo y se lo compara con los 2 primeros del segmento inicial para colocarlo en su posición correcta.<br>
* Se repite este proceso hasta obtener el arreglo completo ordenado.<br>

## Ordenación Rápida (quick_sort)
El algoritmo de ordenación rápida `quick_sort` está basado en la idea de divide y vencerás. Su tiempo de ejecución esperado es de $O(nLog(n))$ para ordenar $n$ elementos.<br>

**Idea del algoritmo**
* Elección del pivote: Se debe elegir en base a algún criterio el elemento que usaremos como pivot; el criterio puede variar y se puede elegir al pivot aleatoriamente, como podemos elegir como pivot al primer elemento, al ultimo, o al elemento del medio del arreglo.<br>
* Partición: Se organiza el arreglo en base al pivote, se colocan a izquierda del pivote los elementos que sean menores a este, los mayores van a su derecha, quedando de esta manera ordenado el pivote en su posición definitiva en el arreglo.<br>
* Llamada recursiva: Se llama al mismo proceso pero ahora para ordenar los subarreglos (el de la izquierda del pivot) y (el de la derecha del pivot).<br>
* Caso base: La recursión acaba cuando se tiene un subarreglo que consta de un unico elemento, ya que un arreglo de tamaño unitario está trivialmente ordenado.<br>


