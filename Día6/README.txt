---DIA 6 ADVENT OF CODE: GUARD GALLIVANT---

En este día, se propone al usuario un problema en el que debe predecir el recorrido de un guardia en un laboratorio del año 1518. El mapa del laboratorio incluye 
obstáculos '#', espacios vacíos '.' y la posición inicial del guardia marcada con un símbolo (^, >, v o <, indicando la dirección inicial del guardia).

El guardia sigue un protocolo de patrullaje estricto:
  Si hay un obstáculo directamente frente a él, gira 90 grados a la derecha.
  Si no hay un obstáculo frente a él, avanza un paso en la dirección en la que está mirando.

La tarea del usuario es:
  Simular el movimiento del guardia a partir de su posición y dirección inicial, siguiendo las reglas descritas.
  Marcar todas las posiciones que visita (incluyendo la inicial) antes de que abandone los límites del mapa.
  Contar cuántas posiciones distintas visita el guardia.

El desafío consiste en implementar una simulación precisa y eficiente que respete las restricciones del mapa y las reglas de movimiento del guardia.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En nuestro caso, hemos optado por emplear una estructura de datos tipo árbol por su capacidad para seguir un historial del recorrido que, en este caso sería el 
movimiento del guardia, y por su facilidad para modelar el problema considerando cada celda como un nodo, las cuales se pueden explorar o analizar sin necesidad de 
construir estructuras adicionales, sin importar la profundidad de las rutas, además de que es relativamente fácil limitar los movimientos realizados.

Este problema se podría abordar también mediante el uso de grafos, el cual permitiría cierta flexibilidad para movimientos en múltiples direcciones, además de su 
generalidad, que es capaz de representar cualquier tipo de conexión entre nodos, no solo las adyacencias inmediatas. Sin embargo, construir un grafo a partir de un 
mapa bidimensional puede ser costoso, ya que se debe analizar cada celda y todas sus conexiones adyacentes, lo que lleva a una complejidad de n*m (n, m representan 
el tamaño del mapa), esto puede llevar a un exceso de consumo de memoria. Cabe recalcar que la implementación de grafos es complicada, ya que implica crear y 
mantener estructuras adicionales, y no es especialmente necesaria si el problema no requiere de rutas óptimas o relaciones complejas entre nodos.

---CÓMO SE HA ABORDADO EL PROBLEMA---
TreeNode: Representa un nodo en el árbol de exploración, que corresponde a una celda específica del mapa, utilizando atributos como x, e y, siendo estas las 
coordenadas de la tabla, y una lista de punteros a los nodos hijos llamada children.

MapTree: Una estructura que representa el árbol completo de exploración, con atributos como root, que es el nodo raíz del árbol (posición inicial del guardia), y 
visited, un conjunto de pares x y que almacena las posiciones visitadas para evitar redundancias.

MapTree(): Método constructor del árbol que lo inicializa creando un nodo raíz en la posición inicial (startX, startY) y la marca como visitada en el conjunto de 
pares visited.

buildTree: Construye el árbol de exploración de manera recursiva desde un nodo dado y recorre las 4 direcciones posibles (dx y dy) para determinar las celdas 
vecinas accesibles desde el nodo actual.
  Comprueba si:
    La celda vecina está dentro de los límites del mapa.
    No es un obstáculo (#).
    No ha sido visitada previamente (visited).
  Si la celda es válida:
    Crea un nuevo nodo para la celda vecina.
    Lo añade a la lista de hijos del nodo actual.
    Marca la celda como visitada.
    Llama recursivamente a buildTree con el nodo recién creado para seguir explorando desde ahí.

traverseTree: Recorre el árbol en profundidad (DFS) para recolectar las posiciones visitadas, añade la posición del nodo actual (x, y) al conjunto visitedPositions 
y llama recursivamente a sí misma para cada hijo del nodo actual.

main: Abre y lee línea por línea el archivo input1.txt, cargando el mapa en un vector de cadenas (map), luego recorre el mapa en busca del carácter ^ para 
identificar las coordenadas iniciales (startX, startY), crea una instancia de MapTree con la posición inicial del guardia, llama a buildTree desde la raíz para 
generar el árbol de exploración basado en las reglas del movimiento, después llama a traverseTree desde la raíz para recolectar todas las posiciones distintas 
visitadas y finalmente muestra el tamaño del conjunto visitedPositions, que indica cuántas celdas diferentes fueron visitadas.

Al final, se calcula el número total de celdas distintas que se pudieron visitar y se imprime por pantalla.
