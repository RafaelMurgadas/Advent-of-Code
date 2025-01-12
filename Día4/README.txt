---DIA 4 ADVENT OF CODE: CERES SEARCH---

En este día, se propone al usuario un problema en el que debe encontrar todas las instancias de la palabra "XMAS" y su variante "X-MAS" en una cuadrícula de 
caracteres. La cuadrícula contiene letras y puede incluir caracteres irrelevantes representados por '.'.

El problema se divide en dos partes principales:
Búsqueda de "XMAS": Encontrar todas las ocurrencias de la palabra "XMAS" en cualquier dirección (horizontal, vertical, diagonal, invertido o superpuesto).
Búsqueda de "X-MAS": Encontrar patrones en forma de "X" que contengan dos instancias de "MAS" (una en cada brazo de la "X").

Parte 1: Búsqueda de "XMAS"
El código realiza una búsqueda exhaustiva de la palabra "XMAS" en todas las posibles direcciones de la cuadrícula utilizando un árbol de sufijos (SuffixTree). Este 
árbol permite realizar búsquedas eficientes al manejar todas las posibles combinaciones de caracteres.

Reglas de búsqueda:
La palabra "XMAS" puede aparecer directamente o invertida.
Se verifica cada fila, columna y diagonal para encontrar todas las ocurrencias.

Parte 2: Búsqueda de "X-MAS"
En la segunda parte del problema, se busca específicamente un patrón en forma de "X" que contenga dos instancias de "MAS". Esto implica buscar diagonales 
específicas donde ambas partes del patrón estén presentes.

Proceso:
Se verifican todas las diagonales para encontrar los patrones "MAS" en forma de "X".
Resultado Final
El resultado final muestra cuántas veces aparecen tanto "XMAS" como "X-MAS" en la cuadrícula. Este enfoque garantiza que ambos patrones sean detectados en cualquier 
disposición de la cuadrícula.

El desafío radica en la eficiencia del algoritmo, especialmente cuando se trabaja con grandes cantidades de datos y múltiples direcciones de búsqueda.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En este caso, hemos optado por utilizar un árbol de sufijos como estructura de datos para resolver el problema de búsqueda de patrones en una cuadrícula de 
caracteres. Esta estructura es ideal debido a su eficiencia en la búsqueda de subcadenas dentro de una cadena más grande, lo que resulta particularmente útil al 
buscar palabras como "XMAS" y "X-MAS" en las filas, columnas y diagonales de la cuadrícula. El uso del árbol de sufijos permite realizar búsquedas rápidas sin tener 
que repetir las comparaciones de subcadenas de forma redundante, lo que mejora significativamente el rendimiento, especialmente con grandes cantidades de datos.

El árbol de sufijos también facilita la búsqueda en varias direcciones de la cuadrícula, al descomponer la cadena en sufijos y almacenar las posiciones donde los 
patrones ocurren. Este enfoque permite encontrar todos los casos de la palabra "XMAS" y el patrón "X-MAS" de manera eficiente, sin necesidad de recorrer manualmente 
toda la cuadrícula. Además, esta estructura optimiza el proceso de búsqueda al evitar la necesidad de realizar búsquedas recursivas o realizar comparaciones 
costosas de manera repetitiva.

Una alternativa a esta solución sería el uso de una tabla hash, que mapearía directamente las posiciones de las palabras a buscar en la cuadrícula. Sin embargo, las 
búsquedas en una tabla hash son simples pero no tan eficientes en casos donde las palabras deben buscarse en diferentes direcciones (horizontal, vertical, 
diagonal), ya que no aprovecha la estructura de sufijos para agilizar la búsqueda en cadenas largas o superpuestas. El árbol de sufijos, por otro lado, optimiza 
este proceso al manejar de manera eficaz las relaciones entre las subcadenas y las posiciones donde se encuentran.

---CÓMO SE HA ABORDADO EL PROBLEMA---
SuffixTree: Implementación de un árbol de sufijos para realizar búsquedas de subcadenas dentro de una cadena, permite verificar rápidamente si una palabra o patrón 
está contenido en la cadena sin tener que recorrerla repetidamente.

build: Función que recibe un patrón (como "XMAS") y busca si existe en el árbol de sufijos. Recorre el árbol siguiendo los caracteres del patrón. Si encuentra todos 
los caracteres en el orden correspondiente, devuelve true, indicando que el patrón está presente. Si en cualquier momento no se encuentra el siguiente carácter en 
el árbol, devuelve false.

AdventDay4: Clase que contiene toda la lógica relacionada con el problema, como la lectura de la cuadrícula de caracteres desde un archivo, la inicialización de 
variables y la ejecución de las búsquedas de las palabras "XMAS" y "X-MAS". También coordina las funciones para realizar la búsqueda en filas, columnas y 
diagonales, y luego imprime los resultados.

xmax_search: Función responsable de iniciar la búsqueda de la palabra "XMAS" en la cuadrícula. Llama a tres funciones principales (row_search, col_search, y 
diag_search) para buscar la palabra en filas, columnas y diagonales, respectivamente. Después de ejecutar estas funciones, las ocurrencias de "XMAS" se cuentan y se 
almacenan en part1.

diag_x_mas_search: Función que busca un patrón específico en forma de "X" dentro de la cuadrícula. El patrón "X-MAS" tiene dos instancias de "MAS" dispuestas en 
forma de "X". La función recorre las diagonales de la cuadrícula y verifica si las subcadenas en esas posiciones forman este patrón especial. Si encuentra el 
patrón, incrementa el contador de part2.

print_results: Función que imprime los resultados de la búsqueda de las palabras "XMAS" y "X-MAS". Muestra los valores de part1 (el número de veces que aparece 
"XMAS") y part2 (el número de veces que aparece "X-MAS" en forma de "X").

row_search: Función que recorre todas las filas de la cuadrícula. Para cada fila, construye un árbol de sufijos utilizando la fila como una cadena de caracteres. 
Luego, busca la palabra "XMAS" en ese árbol de sufijos. Si se encuentra la palabra, incrementa el contador de part1.

col_search: Función que recorre todas las columnas de la cuadrícula. Para cada columna, construye un árbol de sufijos utilizando los caracteres de la columna. 
Luego, busca la palabra "XMAS" en el árbol de sufijos de esa columna. Si la encuentra, incrementa el contador de part1.

diag_search: Función que recorre todas las diagonales posibles dentro de la cuadrícula. Para cada diagonal, construye un árbol de sufijos y busca la palabra "XMAS" 
en esa diagonal. Si la palabra se encuentra en la diagonal, incrementa el contador de part1.

main: Función principal del programa. Crea un objeto de la clase AdventDay4, que gestiona la cuadrícula de letras y las búsquedas de palabras. Llama a la función 
xmas_search para buscar la palabra "XMAS" en todas las direcciones y luego llama a diag_x_mas_search para buscar el patrón "X-MAS" en forma de "X". Finalmente, 
imprime los resultados mediante print_results.
