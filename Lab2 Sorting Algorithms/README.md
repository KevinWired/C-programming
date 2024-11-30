# Laboratorio #2: Cadenas & Algortimos de ordenamiento

Autor: Kevin Santillan

Date: 28 nov, 2024

## Cadenas en C

En C el tipo de cadena de caracteres, (string), no existe y por ende no existe ningún operador para manipular cadenas de caracteres.<br>

Siempre que tengamos algo entre un par de comillas dobles, por ejemplo la palabra queso, ("queso"), tendremos una cadena literal, por lo que en algún lugar de la memoria estará la secuecia de caracteres `'q' 'u' 'e' 's' 'o' '\0'` donde el ultimo caracter visible es seguido del caracter especial cuyos bits son ceros y se lo conoce como caracter nulo, se lo representa con `'\0'` y es quien marca el final de la secuencia de caracteres.<br>

No está especificado por el estándar de C, en que parte de la memoria se guardan las cadenas literales.<br>

Existen $3$ formas de declarar una variable de tipo cadena de caracteres:<br>
- 1: `char *name;`
- 2: `char name[];`
- 3: `char name[20];`<br>

Nota: Un caracter, (`char`), en C tiene un tamaño de 1 byte.

**Ejemplo 1:**

```c
char s1[] = "queso";
```
Lo que sucede con este primer ejemplo, es que se creara un arreglo de caracteres de $6$ caracteres de largo y ahora existe en el stack (pila) y sabemos que es posible modificar las cosas que están en la pila.<br>

**Ejemplo 2:**

```c
char *s2 = "hongo";
```
Exactamente donde se guarda `s2` en memoria, no está definido por el estándar de C. Pero está vez no tenemos un array, sino un puntero a un caracter, al primer caracter de `s2` pero está vez no podremos modificar `s2`. Sucede que si intentamos modificar a `s2`, estaríamos intentando modificar un lugar en la memoria el cual no podemos modificar.<br>

**Diferencias entre `s1` y `s2`:**
`s1` actua como un puntero const y o como un array de caracteres mientras que `s2` en realidad es un puntero y podemos tratarlo como tal.<br>

**Segmentation fault:**

```c
char s3[5]={'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
```
Es muy importante no olvidarse de poner el `'\0'` final ya que de lo contrario `printf()` va a recorrer a `s3[]` por fuera de su rango hasta que aparezca un `'\0'` y al acceder a memoria inválida se producirá eventualmente una violación de segmento.<br>
