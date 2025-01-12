#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

struct Punto{
    int x;
    int y;

    Punto operator+(const Punto& p) const{
        return {x+p.x,y+p.y};
    }

    Punto operator-(const Punto& p) const{
        return {x-p.x,y-p.y};
    }

    Punto operator*(int k) const{
        return {x*k,y*k};
    }

    friend Punto operator*(int k, const Punto& p){
        return p * k;
    }
};

int main(){
    vector<string> mapa;
    string fila;
    ifstream infile("input.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            mapa.push_back(line);
        }
    }
    infile.close();
    int size_mapa = mapa.size();
    int size_fila = mapa[0].size();

    unordered_map<char,vector<Punto>> antenas; //Iteracion para encontrar las antenas 
    for(int i = 0; i < size_mapa; i++){
        for(int j = 0; j < size_fila; j++){
            if(mapa[i][j] != '.'){ //Comprobar que no es un espacio vacio
                antenas[mapa[i][j]].push_back({i,j}); //Almacenar las coordenadas de las antenas
            }
        }
    }
    //Calculo de los antinodos
    for(auto& antena : antenas){
        const vector<Punto> &v = antena.second;
        for(int i = 0; i < v.size(); i++){
            for(int j =0; j<i;j++){
                Punto A = v[i];
                Punto C = v[j];
                //Calculo los 2 puntos reflejados
                for(Punto p: {A+2*(C-A),C+2*(A-C)}){ //Tomando la nocion de que un antinodo es A mÃ¡s 2 veces la distancia de C, y que son simetricos sacamos que P1= A + 2(C-A) y P2= C + 2(A-C)
                    if(0<= p.x && p.x<size_mapa && 0<=p.y && p.y<size_fila){ //Comprueba si el punto esta dentro del mapa
                        mapa[p.x][p.y] = '#';
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < size_mapa; i++){
        for(int j = 0; j < size_fila; j++){
            if(mapa[i][j] == '#'){ //Iteramos sobre el mapa y contamos los antinodos
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
