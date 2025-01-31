---DIA 5 ADVENT OF CODE: PRINT QUEUE---

En este día, se propone al usuario un problema en el que debe verificar si las actualizaciones de un manual de seguridad siguen un conjunto de reglas de orden 
específicas. Estas reglas indican en qué orden deben imprimirse las páginas si ambas están presentes en una actualización.

Se proporcionan dos secciones:
  Reglas de orden: Listas de pares en formato X|Y, lo que significa que si ambas páginas, X y Y, están incluidas en la actualización, X debe imprimirse antes que Y.
  Actualizaciones: Listas de páginas que deben imprimirse en un orden dado.

La tarea del usuario es:
  Determinar qué actualizaciones cumplen todas las reglas aplicables.
  Para cada actualización válida, identificar el número de página en el medio de la lista.
  Sumar los números de las páginas centrales de las actualizaciones válidas y devolver el total.

El desafío es aplicar las reglas solo a las páginas presentes en cada actualización y evaluar eficientemente si el orden es correcto.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En nuestro caso, hemos optado por emplear una estructura de datos tipo grafo debido a su eficiencia con conjuntos de datos grandes, además de para establecer un orden 
topológico que verifica dependencia entre las páginas, las cuales están regidas por una regla a|b, donde la página a debe ir siempre antes que la b en las 
actualizaciones. El uso de un grafo permite verificar que una lista de actualización cumpla con estas dependencias, además de detectar una violación de la dependencia 
transitiva fácilmente debido a que se puede inferir en elementos más avanzados sin necesidad de agregar manualmente relaciones adicionales o hacer búsquedas 
recursivas. Esto permite detener las actualizaciones en caso de que se encuentre una anomalía (como un ciclo).

Este problema se podría solucionar también mediante una tabla hash, ya que el uso de esta permitiría mapear directamente una página a otra que debe ir después,
ademas de que si las reglas son simples, como en este caso (a->b), el acceso a las dependencias sería constante, permitiendo una implementación más simple. En un 
grafo con listas de adyacencia el coste de búsqueda es mayor.

---CÓMO SE HA ABORDADO EL PROBLEMA---

Reglas de dependencias: Las reglas están representadas por pares de números pagina1|pagina2 en el archivo de entrada. Esto significa que la pagina1 debe 
actualizarse antes que la pagina2.

Actualizaciones de páginas: Se da una serie de secuencias que representan las actualizaciones de las páginas en un orden determinado.

Grafo dirigido: Es un mapa (unordered_map) donde las claves son páginas (números enteros) y los valores son vectores de páginas que dependen de esa página 
(es decir, las páginas que deben actualizarse después de la página clave).
Secuencias de actualizaciones: Es un vector de vectores que contiene las secuencias de actualizaciones de las páginas. Cada secuencia representa 
una actualización en un orden dado.

esOrdenCorrectoConGrafo: Esta función recibe una secuencia de actualización y verifica si respeta el orden topológico definido por el grafo de dependencias. Para 
hacerlo, compara las posiciones de las páginas en la secuencia con las restricciones impuestas por las reglas. Si cualquier página en la secuencia aparece después 
de una página que depende de ella (según las reglas), se devuelve false, indicando que el orden es incorrecto. Para determinar la posición de cada página en la 
secuencia, se utiliza un mapa (posicion) que asocia cada página con su índice en la secuencia de actualización.

main: El archivo de entrada se lee línea por línea. Si se detecta una línea vacía, se asume que se ha terminado de leer las reglas, y se comienzan a leer las 
secuencias de actualizaciones. Para cada secuencia de actualización, se verifica si cumple con el orden topológico usando la función esOrdenCorrectoConGrafo.
Si una secuencia es válida, se calcula la página media de esa secuencia (la página en la posición central de la secuencia) y se suma al total acumulado de páginas 
medias.

Al final, el programa imprime la suma de todas las páginas medias que corresponden a las secuencias válidas.
