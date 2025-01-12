---DIA 8 ADVENT OF CODE: RESONANT COLLINEARITY---

En este día, se propone al usuario un problema en el que debe calcular el impacto de una señal emitida por varias antenas en un mapa. Cada antena tiene una 
frecuencia representada por una letra o un número.

Las antenas con la misma frecuencia generan antinodos en ubicaciones alineadas entre ellas, siempre y cuando una de las antenas esté a una distancia doble de la 
otra. Los antinodos se marcan con el símbolo '#'. Sin embargo, las antenas con diferentes frecuencias no crean antinodos entre sí, aunque un antinode puede 
coincidir con la ubicación de una antena.

La tarea del usuario es:
Identificar las ubicaciones de los antinodos generados por las antenas de la misma frecuencia.
Contar cuántas ubicaciones únicas dentro de los límites del mapa contienen un antinode.

El desafío consiste en calcular correctamente las posiciones de los antinodos y determinar cuántas ubicaciones únicas están marcadas por ellos, respetando las 
distancias entre antenas y las frecuencias.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En este problema, hemos optado por utilizar una estructura de datos tipo tabla hash, específicamente un unordered_map, debido a su eficiencia en el manejo de 
grandes conjuntos de datos. El unordered_map permite realizar búsquedas, inserciones y eliminaciones de manera constante, ya que almacena las antenas utilizando un 
esquema de dispersión (hashing). Cada clave en el mapa es un carácter que representa el tipo de antena, y el valor asociado es un vector que contiene las 
coordenadas de las antenas correspondientes a ese tipo. Este enfoque facilita el acceso directo a las antenas y sus ubicaciones en el mapa, mejorando la eficiencia 
general al no requerir búsquedas secuenciales.

El uso de un unordered_map en lugar de un mapa ordenado es clave en este caso, ya que no necesitamos mantener un orden específico de las claves, lo que reduce el 
costo computacional y optimiza el rendimiento del programa, especialmente cuando trabajamos con grandes cantidades de datos. Si bien se podría haber utilizado un 
grafo para modelar las relaciones entre las antenas, la simplicidad y eficiencia del unordered_map hacen que sea la opción ideal para resolver este problema de 
forma rápida y sencilla.

---CÓMO SE HA ABORDADO EL PROBLEMA---
Punto: Define una estructura de datos llamada Punto que contiene dos enteros, x y y, que representan las coordenadas de un punto en el mapa. Además, se sobrecargan 
los operadores +, - y * para permitir operaciones aritméticas entre puntos, lo cual es útil para calcular los reflejos de las antenas y los antinodos.

main: Lee el archivo de entrada con el mapa y encuentra las posiciones de las antenas (caracteres diferentes de '.'), las cuales se almacenan en un unordered_map. 
Luego, el programa calcula los antinodos, que son reflejos simétricos de las antenas sobre el mapa, y marca esos puntos como '#'. Finalmente, el programa cuenta 
cuántos antinodos ('#') se han marcado en el mapa y devuelve ese número.

antenas: Es un unordered_map donde cada clave es un carácter (representando un tipo de antena) y el valor es un vector de puntos que contiene las coordenadas de 
todas las antenas de ese tipo en el mapa.

Al final, se calcula la cantidad de puntos del mapa que se han marcado como antinodos.
