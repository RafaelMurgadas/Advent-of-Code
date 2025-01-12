---DIA 2 ADVENT OF CODE: RED-NOSED REPORTS---

En este día, se propone al usuario un problema en el que debe analizar las secuencias de niveles de seguridad en una planta nuclear. Cada informe contiene una lista 
de niveles que representan la intensidad de distintos sistemas en la planta. El objetivo es determinar cuántos informes son "seguros" según ciertas reglas.

Un informe se considera seguro si ambas condiciones se cumplen:
  Los niveles son o todos crecientes o todos decrecientes.
  Las diferencias entre niveles consecutivos están entre 1 y 3, inclusivo.
  Además, el usuario puede considerar informes con un "error", es decir, informes donde se puede eliminar un solo nivel para que el informe sea seguro.

La tarea del usuario es:
  Leer una lista de informes, cada uno con varios niveles.
  Determinar si cada informe es seguro o puede ser hecho seguro eliminando un solo nivel.
  Contar cuántos informes cumplen con las condiciones de seguridad.

El desafío consiste en implementar una solución que verifique estas reglas y cuente cuántos informes son seguros, optimizando el proceso para manejar una gran 
cantidad de datos de manera eficiente.

---MÉTODOS DE RESOLUCIÓN EMPLEADOS Y POSIBLES---
En este caso, hemos optado por emplear técnicas algorítmicas de divide y vencerás y programación dinámica para abordar el problema de verificar la seguridad de las 
secuencias de niveles. La técnica de divide y vencerás se utiliza para dividir el problema en subproblemas más pequeños, donde cada subsecuencia es validada de 
forma independiente antes de combinar los resultados. Esto permite verificar la seguridad de la secuencia de manera eficiente, dividiendo el trabajo de forma 
recursiva hasta que se alcanzan casos base simples.

La programación dinámica se aplica para almacenar los resultados parciales de las validaciones de subsecuencias, evitando la repetición de cálculos en subproblemas 
ya resueltos. Esta técnica es útil cuando se necesita validar una secuencia en su totalidad, permitiendo reutilizar los resultados intermedios de manera que se 
optimice el tiempo de ejecución.

Juntas, estas técnicas permiten que el algoritmo sea más eficiente en la verificación de la seguridad de secuencias largas, asegurando que las diferencias entre los 
niveles sean correctas y que las secuencias sean crecientes o decrecientes. Además, al aplicar programación dinámica, se mejora la eficiencia al evitar la 
recalculación de resultados redundantes, lo que hace que la solución sea escalable incluso con grandes cantidades de datos.

---CÓMO SE HA ABORDADO EL PROBLEMA---
esSecuenciaSafeRec: Realiza una validación recursiva para verificar si la secuencia de niveles es segura, tanto en la parte creciente como en la parte decreciente. 
Además, verifica que las diferencias entre niveles no sean ni demasiado pequeñas (menor que 1) ni demasiado grandes (mayor que 3).

esSecuenciaSafe: Es la función principal que verifica si una secuencia es segura, llamando a la función recursiva.

esSecuenciaSafeConerror: Si la secuencia no es segura, verifica si se puede hacer segura eliminando un solo nivel.

obtenerSecuenciasSafe: Lee el archivo de entrada y obtiene las secuencias que son seguras. Para cada línea, convierte los números a enteros, y luego verifica si la 
secuencia es segura, ya sea tal cual o eliminando un nivel.

imprimirSecuenciasSafe: Imprime todas las secuencias que son seguras y también muestra el total de secuencias seguras.

main: Llama a obtenerSecuenciasSafe pasando el archivo de entrada y luego imprime las secuencias seguras.

Al final, el programa imprime las secuencias seguras y el número total de secuencias seguras.
