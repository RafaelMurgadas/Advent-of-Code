#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory> // Para std::shared_ptr
#include <fstream>

// Nodo del árbol que representa una celda del mapa
struct TreeNode {
    int x, y; // Coordenadas de la celda
    std::vector<std::shared_ptr<TreeNode>> children; // Hijos del nodo

    TreeNode(int x, int y) : x(x), y(y) {}
};

// Estructura para manejar el árbol y el recorrido
struct MapTree {
    std::shared_ptr<TreeNode> root; // Raíz del árbol (posición inicial del guardia)
    std::set<std::pair<int, int>> visited; // Posiciones visitadas

    // Constructor
    MapTree(int startX, int startY) {
        root = std::make_shared<TreeNode>(startX, startY);
        visited.insert({startX, startY});
    }

    // Construye el árbol recursivamente
    void buildTree(std::shared_ptr<TreeNode> node, const std::vector<std::string>& map, int dx[], int dy[]) {
        for (int dir = 0; dir < 4; ++dir) {
            int nextX = node->x + dx[dir];
            int nextY = node->y + dy[dir];

            // Verificar límites y obstáculos
            if (nextX >= 0 && nextX < map.size() && nextY >= 0 && nextY < map[0].size() && map[nextX][nextY] != '#' && visited.find({nextX, nextY}) == visited.end()) {
                // Crear nuevo nodo hijo
                auto child = std::make_shared<TreeNode>(nextX, nextY);
                node->children.push_back(child);
                visited.insert({nextX, nextY});

                // Llamada recursiva para construir el subárbol
                buildTree(child, map, dx, dy);
            }
        }
    }

    // Recorre el árbol y cuenta las posiciones visitadas
    void traverseTree(std::shared_ptr<TreeNode> node, std::set<std::pair<int, int>>& visitedPositions) {
        visitedPositions.insert({node->x, node->y});
        for (const auto& child : node->children) {
            traverseTree(child, visitedPositions);
        }
    }
};

int main() {
    // Leer el archivo de entrada
    std::ifstream inputFile("input1.txt");
    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Cargar el mapa desde el archivo
    std::vector<std::string> map;
    std::string line;
    while (std::getline(inputFile, line)) {
        map.push_back(line);
    }

    // Direcciones de movimiento (arriba, derecha, abajo, izquierda)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // Encontrar la posición inicial del guardia
    int startX = -1, startY = -1;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '^') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }

    if (startX == -1 || startY == -1) {
        std::cerr << "No se encontró la posición inicial del guardia." << std::endl;
        return 1;
    }

    // Construir el árbol a partir de la posición inicial
    MapTree tree(startX, startY);
    tree.buildTree(tree.root, map, dx, dy);

    // Recorrer el árbol y contar las posiciones distintas visitadas
    std::set<std::pair<int, int>> visitedPositions;
    tree.traverseTree(tree.root, visitedPositions);

    // Imprimir el número de posiciones visitadas
    std::cout << "Posiciones distintas visitadas: " << visitedPositions.size() << std::endl;

    return 0;
}
