#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool esSecuenciaSafeRec(const vector<int>& secuencia, size_t inicio, size_t fin) {
    if (fin - inicio < 1) {
        return true; // Una sub-secuencia de un solo elemento es "safe"
    }

    size_t medio = (inicio + fin) / 2; // Dividir la secuencia en dos partes para hacer un recorrido de divide y venceras
    bool pendiente = (secuencia[medio + 1] > secuencia[medio]);

    for (size_t i = medio + 1; i <= fin; ++i) {
        int diferencia = secuencia[i] - secuencia[i - 1];
        if (abs(diferencia) < 1 || abs(diferencia) > 3 || (pendiente && diferencia < 0) || (!pendiente && diferencia > 0)) {
            return false;
        }
    }

    for (size_t i = medio; i > inicio; --i) {
        int diferencia = secuencia[i] - secuencia[i - 1];
        if (abs(diferencia) < 1 || abs(diferencia) > 3 || (pendiente && diferencia < 0) || (!pendiente && diferencia > 0)) {
            return false;
        }
    }

    return esSecuenciaSafeRec(secuencia, inicio, medio) && esSecuenciaSafeRec(secuencia, medio + 1, fin);
}

bool esSecuenciaSafe(const vector<int>& secuencia) { // Funcion que verifica si una secuencia es safe
    if (secuencia.size() < 2) {
        return false;
    }
    return esSecuenciaSafeRec(secuencia, 0, secuencia.size() - 1);
}

bool esSecuenciaSafeConerror(const vector<int>& secuencia) {
    if (esSecuenciaSafe(secuencia)) {
        return true; // Ya es safe sin modificaciones
    }

    for (size_t i = 0; i < secuencia.size(); ++i) {
        vector<int> nuevaSecuencia = secuencia;
        nuevaSecuencia.erase(nuevaSecuencia.begin() + i); // Eliminar un nivel
        if (esSecuenciaSafe(nuevaSecuencia)) {
            return true; // Es safe al eliminar este nivel
        }
    }

    return false; // No es safe incluso con el error
}

vector<string> obtenerSecuenciasSafe(const string& archivo) { // Funcion que obtiene las secuencias safe de un archivo
    ifstream archivoEntrada(archivo);
    string linea;
    vector<string> secuenciasSafe;

    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        vector<int> secuencia;
        int numero;

        while (ss >> numero) {
            secuencia.push_back(numero);
        }

        if (esSecuenciaSafeConerror(secuencia)) {
            secuenciasSafe.push_back(linea);
        }
    }

    return secuenciasSafe;
}

void imprimirSecuenciasSafe(const vector<string>& secuencias) {
    for (const string& secuencia : secuencias) {
        cout << secuencia << endl;
    }
    cout << "\nNumero total de secuencias Safe: " << secuencias.size() << endl;
}

int main() {
    string archivo = "input.txt";
    vector<string> secuenciasSafe = obtenerSecuenciasSafe(archivo);
    imprimirSecuenciasSafe(secuenciasSafe);
    return 0;
}
