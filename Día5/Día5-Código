#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>

bool isCorrectOrderWithGraph(const std::vector<int>& update, const std::unordered_map<int, std::vector<int>>& graph) {
    // Crear un mapa para almacenar la posición de cada página en la actualización
    std::unordered_map<int, int> position;
    for (int i = 0; i < update.size(); ++i) {
        position[update[i]] = i;
    }

    // Verificar cada nodo y sus vecinos
    for (const auto& [node, neighbors] : graph) {
        if (position.find(node) != position.end()) {
            for (int neighbor : neighbors) {
                if (position.find(neighbor) != position.end() && position[node] > position[neighbor]) {
                    return false; // No cumple con el orden topológico
                }
            }
        }
    }
    return true;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        return 1;
    }

    char buffer[1024];
    std::unordered_map<int, std::vector<int>> graph; // Grafo dirigido para las reglas
    std::vector<std::vector<int>> updates;          // Actualizaciones de páginas
    bool readingRules = true;

    while (inputFile.getline(buffer, sizeof(buffer))) {
        if (strlen(buffer) == 0) { // Detectar línea vacía
            readingRules = false;
            continue;
        }

        if (readingRules) {
            int page1, page2;
            if (sscanf(buffer, "%d|%d", &page1, &page2) == 2) {
                graph[page1].push_back(page2); // Agregar una arista dirigida
            }
        } else {
            std::vector<int> update;
            int page;
            char* token = strtok(buffer, ",");
            while (token != nullptr) {
                sscanf(token, "%d", &page);
                update.push_back(page);
                token = strtok(nullptr, ",");
            }
            updates.push_back(update);
        }
    }

    int sumOfMiddlePages = 0;
    for (const auto& update : updates) {
        if (isCorrectOrderWithGraph(update, graph)) {
            // Calcular la página del medio
            int middlePage = update[update.size() / 2];
            sumOfMiddlePages += middlePage;
        }
    }

    std::cout << "Suma de las páginas medias: " << sumOfMiddlePages << std::endl;

    return 0;
}
