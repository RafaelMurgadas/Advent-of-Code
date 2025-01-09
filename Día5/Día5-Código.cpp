#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
// Función auxiliar para verificar el orden topológico en una actualización
bool esOrdenCorrectoConGrafo(const std::vector<int>& actualizacion, const std::unordered_map<int, std::vector<int>>& grafo) {
    // Crear un mapa para almacenar la posición de cada página en la actualización
    std::unordered_map<int, int> posicion;
    for (int i = 0; i < actualizacion.size(); ++i) {
        posicion[actualizacion[i]] = i;
    }

    // Verificar cada nodo y sus vecinos
    for (const auto& [nodo, vecinos] : grafo) {
        if (posicion.find(nodo) != posicion.end()) {
            for (int vecino : vecinos) {
                if (posicion.find(vecino) != posicion.end() && posicion[nodo] > posicion[vecino]) {
                    return false; // No cumple con el orden topológico
                }
            }
        }
    }
    return true;
}
// Programa principal donde se crea el grafo y calcular la suma de las páginas centrales
int main() {
    std::ifstream archivoEntrada("input.txt");
    if (!archivoEntrada) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        return 1;
    }

    char buffer[1024];
    std::unordered_map<int, std::vector<int>> grafo; // Grafo dirigido para las reglas
    std::vector<std::vector<int>> actualizaciones;  // Actualizaciones de páginas
    bool leyendoReglas = true;

    while (archivoEntrada.getline(buffer, sizeof(buffer))) {
        if (strlen(buffer) == 0) { // Detectar línea vacía
            leyendoReglas = false;
            continue;
        }
        //Esta parte procesa la entrada para construir el grafo y las actualizaciones
        if (leyendoReglas) {
            int pagina1, pagina2;
            if (sscanf(buffer, "%d|%d", &pagina1, &pagina2) == 2) {
                grafo[pagina1].push_back(pagina2); // Agregar una arista dirigida
            }
        } else {
            std::vector<int> actualizacion;
            int pagina;
            char* token = strtok(buffer, ",");
            while (token != nullptr) {
                sscanf(token, "%d", &pagina);
                actualizacion.push_back(pagina);
                token = strtok(nullptr, ",");
            }
            actualizaciones.push_back(actualizacion);
        }
    }
    //Proceso de cálculo del número de páginas medias
    int sumaPaginasMedias = 0;
    for (const auto& actualizacion : actualizaciones) {
        if (esOrdenCorrectoConGrafo(actualizacion, grafo)) {
            // Calcular la página del medio
            int paginaMedia = actualizacion[actualizacion.size() / 2];
            sumaPaginasMedias += paginaMedia;
        }
    }
    //Impresión de los datos calculados
    std::cout << "Suma de las páginas medias: " << sumaPaginasMedias << std::endl;

    return 0;
}
