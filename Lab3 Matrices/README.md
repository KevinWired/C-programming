# Laboratorio #3: Parsing & Matrices
* Autor: Kevin Santillan
* Date: 2 dic, 2024
* Last Update: 3 dic, 2024

## Parsing 

En C `%s` lee hasta toparse con un espacio, tabulación o salto de linea (`\n`), por suerte existe un truco; resulta que podemos leer todo el contenido de una cadena y con `^` marcamos lo que no queremos leer. Por ejemplo:<br>
queremos leer la siguiente cadena, pero ignorando el punto y coma ; entonces hacemos algo como `%[^;]` 
Juan Carlos; Usuahia; 1;<br>

Entonces `%[^;]` leera Juan Carlos deteniendose en el punto y coma (;).<br>

* Otro ejemplo `%[^\n]` leera hasta que el usuario presione enter.<br>

**fscanf**<br>

La función `fscanf` automáticamente saltea los espacios y caracteres `\n` hasta encontrar los datos indicados por el patrón (o falla al encontrar un dato que no respete el patrón indicado). Luego de leer los datos, el cursor de lectura se posiciona justo después de los datos leídos.<br>

Si estamos trabajando con archivos y de antemano se conoce el patrón que tiene y sigue cada una de sus líneas resulta elegante definir una macro;
por ejemplo supongamos que un archivo de texto tiene los datos de sus reglones formateados como `<unsigned int>`:`<char>`:#`<int>`, entonces podemos hacer algo como:

```C
#define "%u:%c:#%d\n"
```

Nota: se recomienta poner el caracter de salto de linea `\n`para evitar problemas con `feof` y `fscanf`.

## La función feof

La funcion `feof` nos dice si hemos alcanzado el final de un archivo binario o archivo de texto. Retornando $0$ (`false`) si aun no se llego al final del y otro valor si se alcanzo el final.<br>
Su prototipo es el siguiente:<br>

```C
int feof(FILE* puntero_a_archivo);
```

