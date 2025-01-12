---DIA 19 ADVENT OF CODE: LINEN LAYOUT---

En este día, se propone al usuario un problema en el que debe determinar cuántos diseños de toallas deseados pueden formarse utilizando patrones de toallas disponibles en cantidades ilimitadas.
Cada patrón de toalla es una secuencia de colores de rayas (r, wr, bwu, etc.), y los diseños deseados son secuencias más largas que deben construirse combinando los patrones disponibles.

El usuario debe cumplir las siguientes reglas:
  Los patrones de toallas no pueden invertirse ni modificarse.
  Los diseños deben formarse exactamente respetando el orden de las rayas.

La tarea del usuario es:
  Analizar cada diseño deseado y determinar si puede construirse utilizando los patrones disponibles.
  Contar cuántos de los diseños deseados son posibles de formar.

El desafío consiste en implementar un enfoque eficiente para validar cada diseño respetando las restricciones de los patrones disponibles.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En nuestro caso, hemos optado por emplear una estructura de datos tipo tabla hash debido a su eficiencia para almacenar y recuperar resultados de subproblemas en la programación dinámica. Esto permite verificar 
rápidamente si un diseño parcial ya ha sido resuelto, reduciendo la cantidad de cálculos redundantes en problemas similares, como determinar si un diseño puede formarse a partir de un conjunto de patrones. La tabla 
hash mapea directamente cada subproblema (estado del diseño) a su solución, proporcionando acceso constante a las soluciones previas. Esto es especialmente útil cuando se trabaja con grandes conjuntos de datos, ya 
que evita la necesidad de realizar búsquedas recursivas profundas.

Este problema se podría solucionar también mediante un árbol implícito, ya que cada diseño puede representarse como un nodo, con sus posibles prefijos válidos como hijos. Esto permitiría explorar las posibles 
combinaciones para formar un diseño usando técnicas de búsqueda como el backtracking. Sin embargo, la memorización en la tabla hash resulta más eficiente en este caso, ya que evita recorrer ramas redundantes en el 
árbol y elimina la necesidad de construir explícitamente una estructura jerárquica.

---CÓMO SE HA ABORDADO EL PROBLEMA---
