---DIA 5 ADVENT OF CODE: GUARD GALLIVANT---

En este día, se propone al usuario un problema en el que debe predecir el recorrido de un guardia en un laboratorio del año 1518. El mapa del laboratorio incluye obstáculos '#', espacios vacíos '.' y la posición inicial del guardia marcada con un símbolo (^, >, v o <, indicando la dirección inicial del guardia).

El guardia sigue un protocolo de patrullaje estricto:
  Si hay un obstáculo directamente frente a él, gira 90 grados a la derecha.
  Si no hay un obstáculo frente a él, avanza un paso en la dirección en la que está mirando.

La tarea del usuario es:
  Simular el movimiento del guardia a partir de su posición y dirección inicial, siguiendo las reglas descritas.
  Marcar todas las posiciones que visita (incluyendo la inicial) antes de que abandone los límites del mapa.
  Contar cuántas posiciones distintas visita el guardia.

El desafío consiste en implementar una simulación precisa y eficiente que respete las restricciones del mapa y las reglas de movimiento del guardia.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En nuestro caso, hemos optado por emplear una estructura de datos tipo árbol por su capacidad para seguir un historial del recorrido que, en este caso sería el movimiento del guardia, y por su facilidad para modelar el problema considerando cada celda como un nodo, las cuales se pueden explorar o analizar sin necesidad de construir estructuras adicionales, sin importar la profundidad de las rutas, además de que es relativamente fácil limitar los movimientos realizados.

Este problema se podría abordar también mediante el uso de grafos, el cual permitiría cierta flexibilidad para movimientos en múltiples direcciones, además de su generalidad, que es capaz de representar cualquier tipo de conexión entre nodos, no solo las adyacencias inmediatas. Sin embargo, construir un grafo a partir de un mapa bidimensional puede ser costoso, ya que se debe analizar cada celda y todas sus conexiones adyacentes, lo que lleva a una complejidad de n*m (n, m representan el tamaño del mapa), esto puede llevar a un exceso de consumo de memoria. Cabe recalcar que la implementación de grafos es complicada, ya que implica crear y mantener estructuras adicionales, y no es especialmente necesaria si el problema no requiere de rutas óptimas o relaciones complejas entre nodos.

---CÓMO SE HA ABORDADO EL PROBLEMA---

