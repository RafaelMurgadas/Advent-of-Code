#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <cstring>

// Estructura para representar una posición en la matriz
struct Position {
    int x, y;

    // Sobrecarga del operador < para permitir el uso de Position en std::set
    bool operator<(const Position& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

int main() {
    // Abrir el archivo de entrada
    std::ifstream inputFile("input1.txt");

    // Vector para almacenar las líneas del mapa
    std::vector<std::string> map;
    std::string line;
    
    // Leer cada línea del archivo y almacenarla en el vector
    while (std::getline(inputFile, line)) {
        map.push_back(line);
    }

    // Arrays para manejar los movimientos del guardia (arriba, derecha, abajo, izquierda)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int direction = 0; // Dirección inicial (0: arriba, 1: derecha, 2: abajo, 3: izquierda)

    Position guard; // Posición actual del guardia
    std::set<Position> visited; // Conjunto de posiciones visitadas

    // Buscar la posición inicial del guardia en el mapa
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '^') { // '^' indica la posición inicial del guardia
                guard = {i, j};
                visited.insert(guard); // Marcar esta posición como visitada
                map[i][j] = '.'; // Reemplazar el símbolo del guardia por suelo libre
                break;
            }
        }
    }

    // Bucle para mover al guardia hasta que se encuentre con un borde o un obstáculo
    while (true) {
        int nextX = guard.x + dx[direction]; // Calcular la próxima posición en x
        int nextY = guard.y + dy[direction]; // Calcular la próxima posición en y

        // Verificar si la próxima posición está fuera de los límites del mapa
        if (nextX < 0 || nextX >= map.size() || nextY < 0 || nextY >= map[0].size()) {
            break; // Salir del bucle si está fuera de los límites
        }

        // Si la próxima posición es un obstáculo ('#')
        if (map[nextX][nextY] == '#') {
            direction = (direction + 1) % 4; // Cambiar dirección (girar a la derecha)
        } else {
            // Mover al guardia a la nueva posición
            guard.x = nextX;
            guard.y = nextY;

            // Marcar la nueva posición como visitada
            visited.insert(guard);
        }
    }

    // Imprimir el número total de posiciones distintas visitadas
    std::cout << "Posiciones distintas visitadas: " << visited.size() << std::endl;

    return 0;
}
    std::cout << "Posiciones distintas visitadas: " << visited.size() << std::endl;

    return 0;
}
